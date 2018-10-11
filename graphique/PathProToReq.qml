import QtQuick 2.11
import QtQuick.Controls 1.4

Item{
    property alias path: pathE
    property alias from_require: pathE.from_require
    property alias to_component: pathE.to_component

    Rectangle
    {
        width: 10
        height: 10
        color:"red"
        x: ((from_require.x + from_require.parent.x + from_require.width /2)+(to_component.x + to_component.parent.x + to_component.width /2))/2
        y: ((from_require.y + from_require.parent.y + from_require.height /2)+(to_component.y + to_component.parent.y + to_component.height /2))/2

        Text{
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

        startX: from_require.x + from_require.parent.x + from_require.width /2
        startY: from_require.y + from_require.parent.y + from_require.height /2

        PathCurve { x: to_component.x + to_component.parent.x + to_component.width /2 ;
                    y: to_component.y + to_component.parent.y + to_component.height /2 }
    }
}
