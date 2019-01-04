import QtQuick 2.5
import QtQuick.Controls 1.4

Item{
    property alias path: pathE
    property alias from_require: pathE.from_require
    property alias to_component: pathE.to_component

    Rectangle
    {
        width: 100
        height: 30

        x: (from_require.get_x() + to_component.get_x() )/2 - width/2
        y: (from_require.get_y() + to_component.get_y() )/2 - height/2

        border.width:3
        border.color: "black"

        Text{

            anchors.centerIn:parent
            text: "link - simple"
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log("click on link")
            }
        }

    }

    Path {
        id: pathE
        property var from_require
        property var to_component

        startX: from_require.get_x()
        startY: from_require.get_y()

        PathCurve { x: to_component.get_x()
                    y: to_component.get_y()}
    }
}
