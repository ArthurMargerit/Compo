import QtQuick 2.11

Rectangle {
    width: 600
    height: 600

    Rectangle {
        width:100
        height:100
        color: "blue"
        id:la

        function pressAndHold(m) {
            color= "red";
            x= m.x+x - height/2
            y= m.y+y - width/2

            console.log("lapin"+m.x+","+m.y);
        }

        MouseArea {
            anchors.fill: parent

            Component.onCompleted: positionChanged.connect(la.pressAndHold)
        }
    }
}
