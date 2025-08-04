#include "databasemanager.h"
#include <QStandardPaths>
#include <QDir>


DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) , m_databaseName("sanayi.db"){
    initializeDatabase();
}

DatabaseManager::~DatabaseManager(){
    if(m_database.isOpen()){
        m_database.close();
    }
}

bool DatabaseManager::initializeDatabase(){
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dataPath);
    QString dbPath = dataPath + "/" + m_databaseName;
    m_database.setDatabaseName(dbPath);

    if (!m_database.open()) {
        qDebug() << "Error: Failed to open database:" << m_database.lastError().text();
        return false;
    }

    return createTables();


}


bool DatabaseManager::createTables()
{
    QSqlQuery query;

    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS transactions (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            date TEXT NOT NULL,
            plate TEXT,
            km INTEGER,
            owner TEXT,
            brand TEXT,
            customer TEXT,
            job_description TEXT,
            debt REAL,
            receivable REAL,
            external REAL,
            spare_part TEXT,
            exit_date TEXT,
            total REAL
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating table:" << query.lastError().text();
        return false;
    }

    // Insert sample data if table is empty
    query.exec("SELECT COUNT(*) FROM transactions");
    if (query.next() && query.value(0).toInt() == 0) {
        addTransaction("9.07.2025", "123", 23123, "", "", "", "", 123, 0, 0, "", "9.07.2025", 123);
        addTransaction("28.07.2024", "12312", 123, "dede", "moka", "lolo", "", 100, 220, 300, "koek", "28.07.2024", 620);
        addTransaction("28.07.2024", "123", 123, "123", "123", "123", "", 123, 123, 123, "123", "28.07.2024", 369);
        addTransaction("28.07.2024", "", 0, "", "", "", "", 0, 0, 0, "", "28.07.2024", 0);
        addTransaction("28.07.2024", "", 0, "", "33", "2", "4", 2323, 0, 0, "", "28.07.2024", 2323);
    }

    return true;
}


bool DatabaseManager::addTransaction(const QString &date, const QString &plate, int km,
                                     const QString &owner, const QString &brand,
                                     const QString &customer, const QString &jobDesc,
                                     double debt, double receivable, double external,
                                     const QString &sparePart, const QString &exitDate, double total)
{
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO transactions (date, plate, km, owner, brand, customer, job_description,
                                debt, receivable, external, spare_part, exit_date, total)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    )");

    query.addBindValue(date);
    query.addBindValue(plate);
    query.addBindValue(km);
    query.addBindValue(owner);
    query.addBindValue(brand);
    query.addBindValue(customer);
    query.addBindValue(jobDesc);
    query.addBindValue(debt);
    query.addBindValue(receivable);
    query.addBindValue(external);
    query.addBindValue(sparePart);
    query.addBindValue(exitDate);
    query.addBindValue(total);

    if (!query.exec()) {
        qDebug() << "Error adding transaction:" << query.lastError().text();
        return false;
    }

    return true;
}


bool DatabaseManager::updateTransaction(int id, const QString &date, const QString &plate, int km,
                                        const QString &owner, const QString &brand,
                                        const QString &customer, const QString &jobDesc,
                                        double debt, double receivable, double external,
                                        const QString &sparePart, const QString &exitDate, double total)
{
    QSqlQuery query;
    query.prepare(R"(
        UPDATE transactions SET
            date = ?, plate = ?, km = ?, owner = ?, brand = ?, customer = ?,
            job_description = ?, debt = ?, receivable = ?, external = ?,
            spare_part = ?, exit_date = ?, total = ?
        WHERE id = ?
    )");

    query.addBindValue(date);
    query.addBindValue(plate);
    query.addBindValue(km);
    query.addBindValue(owner);
    query.addBindValue(brand);
    query.addBindValue(customer);
    query.addBindValue(jobDesc);
    query.addBindValue(debt);
    query.addBindValue(receivable);
    query.addBindValue(external);
    query.addBindValue(sparePart);
    query.addBindValue(exitDate);
    query.addBindValue(total);
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error updating transaction:" << query.lastError().text();
        return false;
    }

    return true;
}


bool DatabaseManager::deleteTransaction(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM transactions WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error deleting transaction:" << query.lastError().text();
        return false;
    }

    return true;
}
