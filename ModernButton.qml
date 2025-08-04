import QtQuick
import QtQuick.Controls
Button{
    id: control
    property color backgroundColor: "#3498db"
    property color hoverColor : Qt.lighter(backgroundColor, 1.1)
    property color pressedColor: Qt.darker(backgroundColor, 1.1)
    property color textColor: "white"
    font.pixelSize: 14
    font.bold: true

    background: Rectangle{
        color: control.pressed ? pressedColor: control.hovered ? hoverColor : backgroundColor
        radius: 6
        border.width: 0

        //Subtle shadow
        Rectangle{
            anchors.fill: parent
            anchors.topMargin: 2
            color: Qt.darker(parent.color, 1.2)
            radius: parent.radius
            z: -1
            opacity: 0.3

        }

        Behavior on color{
            ColorAnimation{
                duration: 150
                easing.type: Easing.OutCubic
            }
        }
    }

    contentItem: Text{
        text: control.text
        font: control.font
        color: textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    //Scale animation on press
    transform: Scale{
        id: scaleTransform
        origin.x: control.width /2
        origin.y : control.height /2
        xScale: control.pressed? 0.95 :1.0
        yScale: control.pressed? 0.95 : 1.0

        Behavior on xScale {
            NumberAnimation{
                duration: 100
                easing.type: Easing.OutCubic

            }
        }
        Behavior on yScale {
            NumberAnimation{
                duration: 100
                easing.type: Easing.OutCubic
            }
        }
    }

    //ripple effect
    Rectangle{
        id: ripple
        anchors.centerIn: parent
        width:0
        height:0
        radius: width / 2
        color: Qt.rgba(255,255,255,0.3)

        SequentialAnimation{
            id: rippleAnimation
            PropertyAnimation{
                target: ripple
                properties: "width,height"
                to: Math.max(control.width,control.height)* 2
                duration: 300
                easing.type: Easing.OutCubic
            }
            PropertyAnimation{
                target: ripple
                properties: "width,height"
                to:0
                duration:0
            }
        }


    }
    Connections{
        target:control
        function onPressed(){
            rippleAnimation.start()
        }
    }


















}
