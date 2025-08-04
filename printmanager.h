#ifndef PRINTMANAGER_H
#define PRINTMANAGER_H


#include <QObject>
#include <QPrinter>
#include <QTextDocument>
#include <QAbstractItemModel>


class PrintManager : public QObject
{
    Q_OBJECT
public:
    explicit PrintManager(QObject *parent = nullptr);
    void setModel(QAbstractItemModel *model);

    Q_INVOKABLE void printWithPreview();

public slots:
    Q_INVOKABLE void printTransactions(QPrinter *printer);
private:
    QAbstractItemModel *m_model = nullptr;
};

#endif // PRINTMANAGER_H
