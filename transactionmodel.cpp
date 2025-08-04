#include "transactionmodel.h"
#include <QDebug>
#include <QSqlRecord>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include "qdatetime.h"
TransactionModel::TransactionModel(QObject *parent):  QSqlTableModel(parent){
    setupModel();
}
void TransactionModel::setupModel(){
    setTable("transactions");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    select();
}


QVariant TransactionModel::data(const QModelIndex &index , int role ) const
{
    if(!index.isValid())
        return QVariant();

    int column = -1;
    switch(role){
    case IdRole:
    case Qt::DisplayRole:
        if (role == IdRole)column = 0;
        else column = index.column();
        break;
    case DateRole: column = 1; break;
    case PlateRole: column = 2; break;
    case KmRole: column = 3; break;
    case OwnerRole: column = 4; break;
    case BrandRole: column = 5; break;
    case CustomerRole: column = 6; break;
    case JobDescriptionRole: column = 7; break;
    case DebtRole: column = 8; break;
    case ReceivableRole: column = 9; break;
    case ExternalRole: column = 10; break;
    case SparePartRole: column = 11; break;
    case ExitDateRole: column = 12; break;
    case TotalRole: column = 13; break;
    default:
        return QSqlTableModel::data(index, role);
    }
    return QSqlTableModel::data(this->index(index.row(),column), Qt::DisplayRole);

}

QHash<int,QByteArray> TransactionModel::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[DateRole] = "date";
    roles[PlateRole] = "plate";
    roles[KmRole] = "km";
    roles[OwnerRole] = "owner";
    roles[BrandRole] = "brand";
    roles[CustomerRole] = "customer";
    roles[JobDescriptionRole] = "jobDescription";
    roles[DebtRole] = "debt";
    roles[ReceivableRole] = "receivable";
    roles[ExternalRole] = "external";
    roles[SparePartRole] = "sparePart";
    roles[ExitDateRole] = "exitDate";
    roles[TotalRole] = "total";
    return roles;
}

void TransactionModel::refresh(){
    select();
}

bool TransactionModel::addTransaction(const QString &date, const QString &plate, int km,
                                      const QString &owner, const QString &brand,
                                      const QString &customer, const QString &jobDesc,
                                      double debt, double receivable, double external,
                                      const QString &sparePart, const QString &exitDate, double total)
{
    int row = rowCount();
    if(!insertRow(row)){
        qDebug() << "failed to insert row";
        return false;
    }

    setData(index(row, 1), date);
    setData(index(row, 2), plate);
    setData(index(row, 3), km);
    setData(index(row, 4), owner);
    setData(index(row, 5), brand);
    setData(index(row, 6), customer);
    setData(index(row, 7), jobDesc);
    setData(index(row, 8), debt);
    setData(index(row, 9), receivable);
    setData(index(row, 10), external);
    setData(index(row, 11), sparePart);
    setData(index(row, 12), exitDate);
    setData(index(row, 13), total);

    if(!submitAll()){
        qDebug() << "failed to submit ";
        revertAll();
        return false;
    }
    return true;
}

bool TransactionModel::updateTransaction(int row, const QString &field, const QVariant &value){
    int column = -1;

    if (field == "date") column = 1;
    else if (field == "plate") column = 2;
    else if (field == "km") column = 3;
    else if (field == "owner") column = 4;
    else if (field == "brand") column = 5;
    else if (field == "customer") column = 6;
    else if (field == "jobDescription") column = 7;
    else if (field == "debt") column = 8;
    else if (field == "receivable") column = 9;
    else if (field == "external") column = 10;
    else if (field == "sparePart") column = 11;
    else if (field == "exitDate") column = 12;
    else if (field == "total") column = 13;

    if (column == -1) return false;

    if (!setData(index(row, column), value)) {
        return false;
    }
    double debt = data(index(row, 8)).toDouble();
    double receivable = data(index(row, 9)).toDouble();
    double external = data(index(row, 10)).toDouble();
    double total = debt + receivable + external;
    setData(index(row,13),total);
    emit totalsChanged();
    return submitAll();
}

bool TransactionModel::deleteTransaction(int row){
    if(!removeRow(row)){
        qDebug() << "failed to remove";
        return false;
    }
    if(!submitAll()){
        qDebug() << "failed to submit ";
        revertAll();
        return false;
    }
    return true;
}

void TransactionModel::clearFilter(){
    setFilter("");
    select();
    emit totalsChanged();
}
void TransactionModel::filterByDateRange(const QString &startDate , const QString &endDate){
    QString filter = QString("date >= '%1' AND date <= '%2'").arg(startDate,endDate);
    setFilter(filter);
    select();
    emit totalsChanged();
}
void TransactionModel::search(const QString &searchText, const QString &startDate, const QString &endDate) {
    QString filter;

    // Tarihleri dd.MM.yyyy formatından yyyyMMdd formatına çevir
    auto formatDate = [](const QString& dateStr) -> QString {
        QDate d = QDate::fromString(dateStr, "dd.MM.yyyy");
        return d.isValid() ? d.toString("yyyyMMdd") : QString();
    };

    QString start = formatDate(startDate);
    QString end = formatDate(endDate);

    QString dateCondition;
    if (!start.isEmpty() && !end.isEmpty()) {
        dateCondition = QString("(SUBSTR(date, 7, 4) || SUBSTR(date, 4, 2) || SUBSTR(date, 1, 2)) BETWEEN '%1' AND '%2'")
        .arg(start).arg(end);
    }

    // Eğer searchText boşsa sadece tarih filtresi uygula
    if (searchText.isEmpty()) {
        if (!dateCondition.isEmpty()) {
            filter = dateCondition;
        } else {
            clearFilter();
            select();
            emit totalsChanged();
            return;
        }
    } else {
        // Hem arama hem tarih filtresi varsa AND ile bağla
        QString searchPattern = QString("'%1'").arg("%" + searchText + "%");
        QString searchCondition = QString(
                                      "plate LIKE %1 OR "
                                      "owner LIKE %1 OR "
                                      "brand LIKE %1 OR "
                                      "customer LIKE %1 OR "
                                      "job_description LIKE %1 OR "
                                      "spare_part LIKE %1"
                                      ).arg(searchPattern);

        if (!dateCondition.isEmpty()) {
            filter = QString("(%1) AND (%2)").arg(dateCondition, searchCondition);
        } else {
            filter = searchCondition;
        }
    }

    setFilter(filter);
    select();
    emit totalsChanged();
}
void TransactionModel::searchTransactions(const QString &searchText){
    if(searchText.isEmpty()){
        clearFilter();
        return;
    }

    QString filter = QString(
                         "date LIKE '%%1%' OR "
                         "plate LIKE '%%1%' OR "
                         "owner LIKE '%%1%' OR "
                         "brand LIKE '%%1%' OR "
                         "customer LIKE '%%1%' OR "
                         "job_description LIKE '%%1%' OR "
                         "spare_part LIKE '%%1%'"
                         ).arg(searchText);

    setFilter(filter);
    select();
    emit totalsChanged();
}


double TransactionModel::sumField(const QString &fieldName) const{
    double sum = 0.0;
    int col = record().indexOf(fieldName);
    if(col < 0){
        return 0.0;
    }
    for(int row = 0; row<rowCount();++row){
        QModelIndex index = this->index(row,col);
        QVariant value = data(index);
        bool ok = false;
        double d = value.toDouble(&ok);
        if(ok){
            sum += d;
        }

    }
    return sum;
}


















