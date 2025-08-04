import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id: root
    color: "white"
    radius: 10
    border.color: "#e0e0e0"
    border.width: 1
    property int currentEditingRow: -1
    property string currentEditingField : ""


    Column{
        anchors.fill: parent
        anchors.margins: 1

        Rectangle{
            width:parent.width
            height:50
            color: "#34495e"
            radius:10
            Rectangle{
                anchors.fill: parent
                anchors.bottomMargin: 10
                color: parent.color
            }
            Row{
                anchors.fill: parent

                HeaderCell{ text: "ID"; width: 60}
                HeaderCell { text: "Date"; width: 100 }
                HeaderCell { text: "Plate"; width: 80 }
                HeaderCell { text: "KM"; width: 80 }
                HeaderCell { text: "Owner"; width: 100 }
                HeaderCell { text: "Brand"; width: 80 }
                HeaderCell { text: "Customer"; width: 100 }
                HeaderCell { text: "Job Description"; width: 120 }
                HeaderCell { text: "Debt"; width: 80 }
                HeaderCell { text: "Receivable"; width: 90 }
                HeaderCell { text: "External"; width: 80 }
                HeaderCell { text: "Spare Part"; width: 100 }
                HeaderCell { text: "Exit Date"; width: 100 }
                HeaderCell { text: "Total"; width: 80 }
                HeaderCell { text: "Actions"; width: 100 }

            }
        }

        //Table Content
        ScrollView{
            width : parent.width
            height : parent.height - 50
            clip: true

            ListView{
                id : listView
                model : transactionModel
                delegate: Rectangle{
                    width: listView.width
                    height: 50
                    color : index % 2 === 0 ? "#ffffff" : "#f8f9fa"

                    Rectangle{
                        anchors.bottom: parent.bottom
                        width: parent.width
                        height: 1
                        color : "#e0e0e0"

                    }
                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled : true
                        onEntered: parent.color = "#ecf0f1"
                        onExited: parent.color = index % 2 ===0 ? "#ffffff" : "#f8f9fa"
                    }

                    Row{
                        anchors.fill: parent

                        DataCell{
                            text: model.id || ""
                            width: 60
                            editable:false
                        }
                        DataCell{
                            text: model.date || ""
                            width: 100
                            fieldName: "date"
                            rowIndex: index
                        }
                        DataCell{
                            text: model.plate || ""
                            width: 80
                            fieldName: "plate"
                            rowIndex: index
                        }
                        DataCell{
                            text: model.km || ""
                            width: 80
                            fieldName: "km"
                            rowIndex: index
                            inputType: "number"
                        }
                        DataCell{
                            text: model.owner || ""
                            width: 100
                            fieldName: "owner"
                            rowIndex: index
                        }
                        DataCell{
                            text: model.brand ||  ""
                            width: 80
                            fieldName: "brand"
                            rowIndex: index
                        }
                        DataCell{
                            text: model.customer || ""
                            width: 100
                            fieldName: "customer"
                            rowIndex: index
                        }
                        DataCell{
                            text: model.jobDescription || ""
                            width: 120
                            fieldName: "jobDescription"
                            rowIndex: index
                        }
                        DataCell{
                            text: model.debt || ""
                            width: 80
                            fieldName: "debt"
                            rowIndex: index
                            inputType: "double"
                        }
                        DataCell{
                            text: model.receivable || ""
                            width: 90
                            fieldName: "receivable"
                            rowIndex: index
                            inputType: "double"
                        }
                        DataCell{
                            text: model.external || ""
                            width: 80
                            fieldName: "external"
                            rowIndex: index
                            inputType: "double"
                        }
                        DataCell{
                            text: model.sparePart || ""
                            width: 80
                            fieldName: "sparePart"
                            rowIndex: index

                        }
                        DataCell{
                            text: model.exitDate || ""
                            width: 80
                            fieldName: "exitDate"
                            rowIndex: index

                        }
                        DataCell{
                            text: model.total || ""
                            width: 80
                            fieldName: "total"
                            rowIndex: index
                            inputType: "double"
                        }
                        //Actions Cell
                        Rectangle{
                            width:100
                            height: parent.height
                            color: "transparent"

                            Row{
                                anchors.centerIn: parent
                                spacing: 5

                                Button{
                                    width: 30
                                    height:30
                                    text: "🗑"
                                    font.pixelSize: 12
                                    background: Rectangle{
                                        color: parent.pressed ? "#c0392b" : "#e74c3c"
                                        radius: 4
                                    }
                                    onClicked:{
                                        confirmDeleteDialog.rowToDelete = index
                                        confirmDeleteDialog.open()
                                    }
                                }

                                Button{
                                    width:30
                                    height:30
                                    text: "📋"
                                    font.pixelSize: 12
                                    background: Rectangle{
                                        color: parent.pressed ? "#c0392b" : "#e74c3c"
                                        radius:4
                                    }
                                    onClicked:{
                                        // Copy row data to clipboard (simplified)
                                        console.log("Copy functionality would be implemented here")
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }

    }
    // Header cell component
    component HeaderCell: Rectangle{
        property alias text : headerText.text
        height: parent.height
        color: "transparent"

        Rectangle{
            anchors.right: parent.right
            width: 1
            height: parent.height
            color: "#2c3e50"

        }
        Text{
            id:headerText
            anchors.centerIn: parent
            color: "white"
            font.bold: true
            font.pixelSize: 14
            elide: Text.ElideRight
        }
    }
    //DataCell component with inline editing
    component DataCell: Rectangle{
        property alias text: cellText.text
        property string fieldName: ""
        property int rowIndex : -1
        property bool editable: true
        property string inputType : "text" // text number double

        height: parent.height
        color: "transparent"


        Rectangle{
            anchors.right: parent.right
            width: 1
            height: parent.height
            color : "#e0e0e0"
        }
        Text{
            id: cellText
            anchors.centerIn: parent
            color: "#2c3e50"
            font.pixelSize: 11
            elide: Text.ElideRight
            width: parent.width - 10
        }
        TextField{
            id: editField
            anchors.fill: parent
            anchors.margins: 2
            visible:false
            font.pixelSize: 11

            validator:{
                if(inputType === "number") return intValidator
                if(inputType === "double") return doubleValidator
                return null
            }

            IntValidator{
                id: intValidator
                bottom: 0
            }
            DoubleValidator{
                id: doubleValidator
                bottom: 0
                decimals: 2
            }

            onAccepted:{
                if(editable && fieldName != ""){
                    var value = text
                    if(inputType === "number") value = parseInt(text) || 0
                    if(inputType === "double") value = parseFloat(text) || 0
                    if(transactionModel.updateTransaction(rowIndex,fieldName,value)){
                        cellText.text = text


                        //update total if its financial field
                        if(fieldName === "debt" || fieldName ==="receivable"||fieldName === "external" ){



                            transactionModel.updateTransaction(rowIndex, "total", value)
                            transactionModel.refresh()
                        }
                    }
                }
                visible = false
                cellText.visible = true
                root.currentEditingRow = -1
                root.currentEditingField = ""
            }

            onActiveFocusChanged: {
                if(!activeFocus){
                    accepted()
                }
            }
        }

        MouseArea{
            anchors.fill: parent
            enabled: editable
            onDoubleClicked:{
                if(fieldName != ""){
                    root.currentEditingRow = rowIndex
                    root.currentEditingField = fieldName
                    editField.text = cellText.text
                    cellText.visible = false
                    editField.visible = true
                    editField.forceActiveFocus()
                    editField.selectAll()

                }
            }
        }

    }

    Dialog{
        id:confirmDeleteDialog
        title:"Confirm Delete"
        modal:true
        anchors.centerIn: parent
        width:300
        height:150
        property int rowToDelete : -1

        background: Rectangle{
            color:"white"
            radius:10
            border.color: "#e0e0e0"

        }
        Column{
            anchors.centerIn: parent
            spacing:20
            Text{
                text: "Are you sure you want to delete this transaction?"
                color: "#2c3e50"
                font.pixelSize: 14
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Row{
                spacing:10
                anchors.horizontalCenter: parent.horizontalCenter
                Button{
                    text: "Delete"
                    background: Rectangle{
                        color: parent.pressed ? "#c0392b" : "#e74c3c"
                        radius:5
                    }
                    onClicked:{
                        if (transactionModel.deleteTransaction(confirmDeleteDialog.rowToDelete)) {
                            transactionModel.refresh()
                        }
                        confirmDeleteDialog.close()
                    }
                }
                Button{
                    text: "Cancel"
                    background: Rectangle{
                        color: parent.pressed ? "#7f8c8d" : "#95a5a6"
                        radius:5
                    }
                    onClicked: confirmDeleteDialog.close()
                }
            }
        }
    }
}



