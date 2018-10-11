import QtQuick 2.0
import QtQuick.Controls 1.4


Item{
    property alias name: txt.text
    height:30

    width: 100
    //height: childrenRect.height

    Rectangle
    {
        id:ca
        anchors.left: parent.left
        anchors.topMargin: 5
        anchors.top: parent.top
        width:20
        height:20
        color:"green"
    }

    Text
    {
        id: txt
        text:"None"
        verticalAlignment: Text.AlignVCenter
        color:"blue"
        anchors.leftMargin: 5
        anchors.top : parent.top
        anchors.left : ca.right
        anchors.right : parent.right
        anchors.bottom : parent.bottom

    }
}
