import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.11

Rectangle{
    property alias type: type.text
    property alias name: name.text
    property alias val: value.text

    height: 30
    width: 200

    RowLayout
    {
        height:30
        width:200
        spacing: 5

        Text{
            id:type
            text:"T"
        }

        Text{
            id:name
            text:"N"
        }

        TextField{
            id:value
            text:"lapin"
            Layout.fillWidth:true
            Layout.leftMargin:10
        }
    }

}

