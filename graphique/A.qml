import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id:comp
    width: 200
    height: 100

    property alias p1: pro1
    property alias r1: req1

    property alias p2: pro2
    property alias r2: req2

    border.width:1
    border.color: "black"


    function pressAndHold(m) {
        x= m.x+x - width/2
        y= m.y+y - height/2

    }

    MouseArea {
        anchors.fill: parent

        Component.onCompleted: positionChanged.connect(comp.pressAndHold)
    }

    Rectangle {
        id: pro1

        anchors.topMargin: 5
        anchors.right: comp.left
        anchors.rightMargin: 10
        anchors.top: parent.top

        width: 20
        height: 20

        color: "green"

        Text {
            anchors.right: parent.left
            anchors.rightMargin: 10
            text: "pro1"
        }

        function pressAndHold(m)
        {
            console.log("connection")
        }
        MouseArea {
            anchors.fill: parent

            Component.onCompleted: positionChanged.connect(pro1.pressAndHold)
        }
    }

    Rectangle {
        id: pro2

        anchors.topMargin: width+5+5
        anchors.right: comp.left
        anchors.rightMargin: 10
        anchors.top: parent.top

        width: 20
        height: 20

        color: "green"

        Text {
            anchors.right: parent.left
            anchors.rightMargin: 10
            text: "pro2"
        }
    }

    Rectangle {
        id: pro3

        anchors.topMargin: width*2+5+10
        anchors.right: comp.left
        anchors.rightMargin: 10
        anchors.top: parent.top

        width: 20
        height: 20

        color: "green"

        Text {
            anchors.right: parent.left
            anchors.rightMargin: 10
            text: "pro3"
        }
    }


    Rectangle {
        id:req1

        anchors.topMargin:5
        anchors.top: parent.top
        anchors.left: comp.right
        anchors.leftMargin: 10

        width: 20
        height: 20
        color: "blue"
        Text {
            anchors.left: parent.right
            anchors.leftMargin: 10
            text: "req1"
        }
    }
        Rectangle {
            id:req2

            anchors.topMargin:5 + (width+5)*1
            anchors.top: parent.top
            anchors.left: comp.right
            anchors.leftMargin: 10

            width: 20
            height: 20
            color: "blue"
            Text {
                anchors.left: parent.right
                anchors.leftMargin: 10
                text: "req2"
            }

    }

    Text {
        id:comp_name
        anchors.centerIn: parent
        text: "COMP_NAME"
    }

    Text {

        anchors.top: comp_name.bottom
        anchors.horizontalCenter : comp_name.horizontalCenter
        text: "TYPE"
    }
}
