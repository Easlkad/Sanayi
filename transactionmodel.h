#ifndef TRANSACTIONMODEL_H
#define TRANSACTIONMODEL_H
#include <QtSql/QSqlTableModel>
#include <QObject>

class TransactionModel : public QSqlTableModel{
    Q_OBJECT

public:
    enum Roles{
        IdRole = Qt::UserRole + 1,
        DateRole,
        PlateRole,
        KmRole,
        OwnerRole,
        BrandRole,
        CustomerRole,
        JobDescriptionRole,
        DebtRole,
        ReceivableRole,
        ExternalRole,
        SparePartRole,
        ExitDateRole,
        TotalRole

    };

    explicit TransactionModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index , int role = Qt::DisplayRole) const override;
    QHash <int , QByteArray> roleNames() const override;
    Q_INVOKABLE void refresh();
    Q_INVOKABLE bool addTransaction(const QString &date, const QString &plate, int km, const QString &owner, const QString &brand
                                    ,const QString &customer, const QString &jobDesc, double debt, double receivable, double external,
                                    const QString &sparePart, const QString &exitDate, double total );
    Q_INVOKABLE bool updateTransaction(int row, const QString &field,const QVariant &value);
    Q_INVOKABLE bool deleteTransaction(int row);
    Q_INVOKABLE void searchTransactions(const QString &searchText);
    Q_INVOKABLE void search(const QString &searchText, const QString &startDate, const QString &endDate);
    Q_INVOKABLE void filterByDateRange(const QString &startDate, const QString &endDate);
    Q_INVOKABLE void clearFilter();
    Q_INVOKABLE double sumField(const QString &fieldName)const;




signals:
    void totalsChanged();
private:
    void setupModel();
};


#endif // TRANSACTIONMODEL_H
