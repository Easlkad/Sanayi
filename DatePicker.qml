import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
Rectangle{
    id:root
    height:40
    color:"white"
    border.color: "#bdc3c7"
    border.width: 1
    radius: 5

    property alias dateText : dateInput.text
    property date selectedDate : new Date()


    Popup{
        id: calendarPopup
        modal: true
        focus:true
        x: root.mapToItem(null,0,root.height).x
        y: root.mapToItem(null,0,root.height).y + 5
        contentItem: Rectangle{
            width:250
            height: 250
            color: "white"
            border.color: "#bdc3c7"
            border.width: 1
            radius: 4

             // Todo: Add Calendar here



        }
    }

    TextField{
        id:dateInput
        anchors.fill: parent
        anchors.margins: 2
        font.pixelSize: 12
        color: "#2c3e50"
        placeholderText: "DD.MM.YYYY"
        verticalAlignment: Text.AlignVCenter

        background: Rectangle{
            color: "transparent"
        }
        validator: RegularExpressionValidator{
            regularExpression: /^(\d{1,2})\.(\d{1,2})\.(\d{4})$/
        }
        onTextChanged:{
            //Parse date from dd.mm.yyyy format
            var parts = text.split('.');
            if(parts.length === 3){
                var day = parseInt(parts[0]);
                var month = parseInt(parts[1])-1; // Js months are 0-based
                var year = parseInt(parts[2]);
                if(!isNaN(day) && !isNaN(month) && !isNaN(year)){
                    selectedDate = new Date(year,month,day)

                }


            }
        }
    }
    //calendar icon
    Text{
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.verticalCenter: parent.verticalCenter
        text: "📅"
        font.pixelSize: 14
        color: "#7f8c8d"

        MouseArea{
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked:{
                //Simple date picker todo implement more sophisticated one
                //calendarPopup.open()
                dateInput.text = Qt.formatDate(new Date(), "dd.MM.yyyy")
            }

        }
    }
    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        acceptedButtons: Qt.NoButton
        onEntered: parent.border.color = "#3598db"
        onExited: parent.border.color = "#bdc3c7"

    }
}
