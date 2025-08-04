#include "transactionmodel.h"
#include "DatabaseManager.h"
#include "printmanager.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtSql/QSqlDatabase>
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    app.setApplicationName("Sanayi Management");
    app.setApplicationVersion("1.0");
    app.setOrganizationName("Oto Teknik");

    //Initialize Database
     DatabaseManager dbManager;
     TransactionModel transactionModel;
     PrintManager printManager;
     printManager.setModel(&transactionModel);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dbManager",&dbManager);
    engine.rootContext()->setContextProperty("transactionModel",&transactionModel);
    engine.rootContext()->setContextProperty("printManager", &printManager);



    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);


    //engine.loadFromModule("Sanayi", "Main");
    engine.load(url);
    return app.exec();
}
