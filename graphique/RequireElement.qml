import QtQuick 2.0
import QtQuick.Controls 1.4

 Item{
    property alias name: txt.text
     height:30
     width:100
     
     Rectangle
    {
        id:cb
        anchors.right: parent.right
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
        horizontalAlignment: Text.AlignRight
        anchors.rightMargin: 5
        anchors.top : parent.top
        anchors.right : cb.left
        anchors.left : parent.left
        anchors.bottom : parent.bottom
    }
}
