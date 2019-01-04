import QtQuick 2.0
import QtQuick.Controls 1.4

 Item{
    property alias name: txt.text
     height:30
     width:100

     property string stop : "main"

    function get_x()
    {      
      return get_position_x_until(cb) + cb.width/2
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


    function get_y()
    {
      return get_position_y_until(cb) +cb.height/2
    }

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
