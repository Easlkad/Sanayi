#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QObject>
#include <QDebug>


class DatabaseManager : public QObject{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool initializeDatabase();
    bool createTables();
public slots:
    bool addTransaction(const QString &date, const QString &plate, int km,
                        const QString &owner, const QString &brand,
                        const QString &customer, const QString &jobDesc,
                        double debt, double receivable, double external,
                        const QString &sparePart, const QString &exitDate, double total);

    bool updateTransaction(int id, const QString &date, const QString &plate, int km,
                           const QString &owner, const QString &brand,
                           const QString &customer, const QString &jobDesc,
                           double debt, double receivable, double external,
                           const QString &sparePart, const QString &exitDate, double total);

    bool deleteTransaction(int id);

private:
    QSqlDatabase m_database;
    QString m_databaseName;
};




#endif // DATABASEMANAGER_H
