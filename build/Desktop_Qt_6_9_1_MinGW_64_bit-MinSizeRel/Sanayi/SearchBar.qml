import QtQuick
import QtQuick.Controls 2.15

Rectangle{
    id:root
    color: "white"
    radius:20
    border.color: "#bdc3c7"
    border.width: 1

    property alias searchText: searchInput.text
    signal searchTriggered(string text)

    function clearSearch(){
        searchInput.text = ""
    }

    Row{
        anchors.fill: parent
        anchors.margins: 2

        //Search Icon
        Rectangle{
            width: 36
            height: parent.height
            color: "transparent"
            Text{
                anchors.centerIn: parent
                text: "🔍"
                font.pixelSize: 16
                color: "#7f8c8d"
            }
        }

        TextField{
            id: searchInput
            width: parent.width - 72 // account for both icons
            height: parent.height
            font.pixelSize: 14
            color: "#2c3e50"
            placeholderText: "Search Transactions..."
            verticalAlignment: Text.AlignVCenter
            background: Rectangle{
                color: "transparent"
            }
            onTextChanged:{
                searchTriggered(text)
            }
            Keys.onEscapePressed: {
                text = ""
                focus = false
            }
        }

        //Clear Button
        Rectangle{
            width: 36
            height: parent.height
            color: "transparent"
            visible: searchInput.text.length > 0

            Text{
                anchors.centerIn: parent
                text: "x"
                font.pixelSize: 14
                color: "#e74c3c"
            }

            MouseArea{
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    searchInput.text = ""
                    searchInput.focus = false
                }
            }
        }

    }
    states: [
    State{
            name:"focused"
            when: searchInput.activeFocus
            PropertyChanges {
                target: root
                border.color: "#3498db"
                border.width: 2


            }
        },
    State{
            name:"hovered"
            when: MouseArea.containsMouse && !searchInput.activeFocus
            PropertyChanges {
                target: root
                border.color: "#3498db"

            }
        }

    ]

    transitions: Transition{
        PropertyAnimation{
            properties: "border.color , border.width"
            duration: 150
            easing.type: Easing.OutCubic
        }
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        acceptedButtons: Qt.NoButton
        onClicked: searchInput.forceActiveFocus()
    }

}
