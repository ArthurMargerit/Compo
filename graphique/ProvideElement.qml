import QtQuick 2.0
import QtQuick.Controls 1.4


Item{
    property alias name: txt.text
    height:30

    function get_x()
    {
      return get_position_x_until(ca) + ca.width/2
    }

    function get_y()
    {
      return get_position_y_until(ca) + ca.height/2
    }

    function get_position_x_until(cu)
         {

         if(cu == null)
               return 0

         return cu.x + get_position_x_until(cu.parent)
         }

    function get_position_y_until(cu)
         {

         if(cu == null)
               return 0

         return cu.y + get_position_y_until(cu.parent)
         }



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
