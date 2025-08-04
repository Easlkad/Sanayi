import QtQuick
import QtQuick.Layouts 1.15
import QtQuick.Controls
ApplicationWindow {
    id:window
    width: 1400
    height: 800
    visible: true
    title: qsTr("Hello World")

    property alias startDateText: startDatePicker.dateText
    property alias endDateText: endDatePicker.dateText

    //Modern color scheme
    color: "#f5f5f5"
    header: Rectangle{
        height:80
        color:"#2c3e50"

        RowLayout{
            anchors.fill: parent
            anchors.margins: 20
            Text{
                text: "Oto Teknik Sanayi"
                font.pixelSize: 24
                font.bold: true
                color: "white"
            }
            Item{Layout.fillWidth: true}
            SearchBar{
                id: searchBar
                Layout.preferredWidth: 300
                Layout.preferredHeight: 40
                onSearchTriggered:{
                    if(searchText.length === 0){
                        transactionModel.clearFilter()
                    }else{
                        transactionModel.searchTransactions(searchText)
                    }

                }
            }
        }
    }

    ColumnLayout{
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20

        //Date Range And Controls
        Rectangle{
            Layout.fillWidth: true
            height: 80
            color: "white"
            radius: 10
            border.color: "#e0e0e0"
            border.width: 1

            RowLayout{
                anchors.fill: parent
                anchors.margins: 20
                spacing: 20

                Text{
                    text: "Start Date"
                    font.pixelSize: 14
                    color: "#2c3e50"

                }
                DatePicker{
                    id: startDatePicker
                    Layout.preferredWidth: 150
                    dateText: "1.01.2025"
                }
                Text{
                    text: "End Date"
                    font.pixelSize: 14
                    color: "#2c3e50"
                }
                DatePicker{
                    id: endDatePicker
                    Layout.preferredWidth: 150
                    dateText: "1.01.2025"
                }
                ModernButton{
                    text: "Clear filter"
                    backgroundColor: "#95a5a6"
                    onClicked:{
                        transactionModel.clearFilter()
                        searchBar.clearSearch()
                    }
                }
                ModernButton{
                    text:"Print"
                    backgroundColor: "#95a5a6"
                    onClicked:{
                        printManager.printWithPreview()
                    }
                }

                Item{
                    Layout.fillWidth: true
                }
                ModernButton{
                    text: "➕ Add Transaction"
                    backgroundColor: "#27ae60"
                    onClicked:{
                        addTransactionDialog.open()
                    }
                }


            }


        }
        //Transaction Table
        TransactionTable{
            id: transactionTable
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Column{
            spacing: 8
            Text {
                id:debtTotal
                text: " debt total: " + transactionModel.sumField("debt").toFixed(2)
            }
            Text {
                id:receivableTotal
                text: " receivable total: " + transactionModel.sumField("receivable").toFixed(2)
            }
            Text {
                id:externalTotal
                text: " external total: " + transactionModel.sumField("external").toFixed(2)
            }
            Text {
                id:totalTotal
                text: " total total: " + transactionModel.sumField("total").toFixed(2)
            }
        }
    }

    Dialog{
        id: addTransactionDialog
        title: "Add New Transaction"
        width:600
        height:500
        modal: true
        anchors.centerIn: parent


        property alias dateField: dateInput.text
        property alias plateField: plateInput.text
        property alias kmField: kmInput.text
        property alias ownerField: ownerInput.text
        property alias brandField: brandInput.text
        property alias customerField: customerInput.text
        property alias jobDescField: jobDescInput.text
        property alias debtField: debtInput.text
        property alias receivableField: receivableInput.text
        property alias externalField: externalInput.text
        property alias sparePartField: sparePartInput.text
        property alias exitDateField: exitDateInput.text

        background: Rectangle{
            color:"white"
            radius:10
            border.color: "#e0e0e0"
        }

        ScrollView{
            anchors.fill: parent
            anchors.margins: 20

            GridLayout{
                width: parent.width
                columns: 2
                columnSpacing: 20
                rowSpacing: 15

                //Input Fields
                Text{text:"Date:";color:"#2c3e50"}
                TextField{
                    id: dateInput
                    Layout.fillWidth: true
                    placeholderText: "DD.MM.YYYY"
                    text: Qt.formatDate(new Date(),"dd.MM.yyyy")
                }
                Text{text:"Plate:";color:"#2c3e50"}
                TextField{
                    id: plateInput
                    Layout.fillWidth: true
                    placeholderText: "License Plate"
                }
                Text{text:"KM:";color:"#2c3e50"}
                TextField{
                    id: kmInput
                    Layout.fillWidth: true
                    placeholderText: "Kilometers"
                    validator: IntValidator {bottom:0}
                }
                Text{text:"Owner:";color:"#2c3e50"}
                TextField{
                    id: ownerInput
                    Layout.fillWidth: true
                    placeholderText: "Owner Name"

                }
                Text{text:"Brand:";color:"#2c3e50"}
                TextField{
                    id: brandInput
                    Layout.fillWidth: true
                    placeholderText: "Vehicle Brand"

                }
                Text{text:"Customer:";color:"#2c3e50"}
                TextField{
                    id: customerInput
                    Layout.fillWidth: true
                    placeholderText: "Customer Name"

                }
                Text{text:"Job Description:";color:"#2c3e50"}
                TextField{
                    id: jobDescInput
                    Layout.fillWidth: true
                    placeholderText: "Job Description"

                }
                Text{text:"Debt:";color:"#2c3e50"}
                TextField{
                    id: debtInput
                    Layout.fillWidth: true
                    placeholderText: "0.00"
                    validator: DoubleValidator{bottom:0;decimals:2}

                }
                Text{text:"Receivable:";color:"#2c3e50"}
                TextField{
                    id: receivableInput
                    Layout.fillWidth: true
                    placeholderText: "0.00"
                    validator: DoubleValidator{bottom:0;decimals:2}

                }
                Text{text:"External:";color:"#2c3e50"}
                TextField{
                    id: externalInput
                    Layout.fillWidth: true
                    placeholderText: "0.00"
                    validator: DoubleValidator{bottom:0;decimals:2}

                }
                Text{text:"Spare Part:";color:"#2c3e50"}
                TextField{
                    id: sparePartInput
                    Layout.fillWidth: true
                    placeholderText: "Spare Part Details"

                }
                Text{text:"Exit Date:";color:"#2c3e50"}
                TextField{
                    id: exitDateInput
                    Layout.fillWidth: true
                    placeholderText: "DD.MM.YYYY"
                    text: Qt.formatDate(new Date(), "dd.MM.yyyy")

                }


            }
        }

        footer: DialogButtonBox{
            ModernButton{
                text:"ADD"
                backgroundColor: "#27ae60"
                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
                onClicked:{
                    var debt = parseFloat(addTransactionDialog.debtField) || 0;
                    var receivable = parseFloat(addTransactionDialog.receivableField) || 0;
                    var external = parseFloat(addTransactionDialog.externalField) || 0;
                    var total = debt + receivable + external;

                    if(transactionModel.addTransaction(dateInput.text,plateInput.text, parseInt(kmInput.text) || 0,
                                                       ownerInput.text, brandInput.text,customerInput.text,jobDescInput.text,debt,
                                                       receivable,external,sparePartInput.text,exitDateInput.text,total)){
                         dateInput.text = Qt.formatDate(new Date(),"dd.MM.yyyy")
                        plateInput.text = ""
                        kmInput.text = ""
                        ownerInput.text = ""
                        brandInput.text = ""
                        customerInput.text = ""
                        jobDescInput.text = ""
                        debtInput.text = ""
                        receivableInput.text = ""
                        externalInput.text = ""
                        sparePartInput.text = ""
                        exitDateInput.text = Qt.formatDate(new Date(), "dd.MM.yyyy")

                        addTransactionDialog.close()
                    }
                }
            }

            ModernButton{
                text: "Cancel"
                backgroundColor: "#95a5a6"
                DialogButtonBox.buttonRole : DialogButtonBox.RejectRole
            }
        }
    }

    Connections{
        target:transactionModel
        onTotalsChanged:{
            debtTotal.text = " debt total: " + transactionModel.sumField("debt").toFixed(2)
            receivableTotal.text = " receivable total: " + transactionModel.sumField("receivable").toFixed(2)
            externalTotal.text = " external total: " + transactionModel.sumField("external").toFixed(2)
            totalTotal.text = " total total: " + transactionModel.sumField("total").toFixed(2)
        }
    }

}

