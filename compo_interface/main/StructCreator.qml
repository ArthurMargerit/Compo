import QtQuick 2.3
import QtQuick.Controls 1.4

Item
{
    height:parent.height
    anchors.left:parent.left
    anchors.top:parent.top
    anchors.bottom:parent.bottom

    Column{

        anchors.left:parent.left
        width:200

        anchors.top:parent.top
        anchors.bottom:parent.bottom

        Item{
            height:30
            anchors.right:parent.right
            anchors.left:parent.left

            Text{
                text:"Struct"
                horizontalAlignment:Text.AlignHCenter
                verticalAlignment:Text.AlignVCenter
                anchors.left: parent.left
                width: parent.width - 20
                height:30
            }
            Button
            {
                width:30
                height:30
                anchors.right:parent.right
                text:"+"
            }
        }

        TreeView {
            height: parent.height-30
            width:parent.width
            TableViewColumn {
                title: "NameSpace"
                role: "fileName"
            }

            TableViewColumn {
                title: "Name"
                role: "fileName"
            }

            TableViewColumn {
                title: "Déclaration"
                role: "fileName"
            }

            //model: fileSystemModel
        }
    }


    Column{

        anchors.right:parent.right
        width:200

        anchors.top:parent.top
        anchors.bottom:parent.bottom
}
}
