import QtQuick 2.3
import QtQuick.Controls 1.4

Item
{

    height:parent.height
    anchors.left:parent.left
    anchors.top:parent.top
    anchors.bottom:parent.bottom

    Column{
        anchors.top:parent.top
        anchors.bottom:parent.bottom
        Item{
            height:30
            anchors.right:parent.right
            anchors.left:parent.left

            Text{
                text:"Déploiment"
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
            width:200

            TableViewColumn {
                title: "Name"
                role: "fileName"
                width: 200
            }
            //model: fileSystemModel
        }

    }

    Rectangle
    {
        color:"blue"

    }

    Column
    {
        anchors.right: parent.right
        height:parent.height

        TreeView {
            height:parent.height/3

            TableViewColumn {
                title: "Name"
                role: "fileName"
                width: 200
            }
            //model: fileSystemModel
        }

        TreeView {
            height:parent.height/3

            TableViewColumn {
                title: "Name"
                role: "fileName"
                width: 200
            }
//            model: fileSystemModel
        }

        TreeView {
            height:parent.height/3


            TableViewColumn {
                title: "Namea"
                role: "fileName"
                width: 200
            }

            //model: fileSystemModel
        }

    }
}

