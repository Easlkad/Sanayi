#include "printmanager.h"
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QTextDocument>


PrintManager::PrintManager(QObject *parent) : QObject(parent){

}

void PrintManager::setModel(QAbstractItemModel *model){
    m_model = model;
}

void PrintManager::printWithPreview(){
    if (!m_model)
        return;

    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer);
    connect(&preview, &QPrintPreviewDialog::paintRequested, this, &PrintManager::printTransactions);
    preview.exec();  // Önizleme açılır, kullanıcı oradan yazdırabilir
}

void PrintManager::printTransactions(QPrinter *printer){
    if(!m_model){
        return;
    }
/*
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageMargins(QMarginsF(15,15,15,15));

    QPrintDialog dialog(&printer);
    dialog.setWindowTitle("Print Transactions");
    if(dialog.exec() != QDialog::Accepted) return;
*/
    QString html = "<h2>Transactions</h2><table border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr><th>ID</th>"
            "<th>Date</th>"
            "<th>Plate</th>"
            "<th>KM</th>"
            "<th>Owner</th>"
            "<th>Brand</th>"
            "<th>Customer</th>"
            "<th>Job Description</th>"
            "<th>Debt</th>"
            "<th>Receivable</th>"
            "<th>External</th><th>Spare Part</th><th>Exit Date</th><th>Total</th></tr>";
    for (int row = 0; row < m_model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < m_model->columnCount(); ++col) {
            QString text = m_model->data(m_model->index(row, col)).toString();
            html += "<td>" + text + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";

    QTextDocument doc;
    doc.setHtml(html);
    doc.print(printer);
}
