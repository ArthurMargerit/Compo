import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Rectangle {

    property alias prov: provideList
    property alias req : requireList

    id:comp
    border.color: "black"
    border.width: 3

    height: cc.height + 60
    width: cc.width

    function max(a,b)
    {
        if(a>b)
            return a
        else
            return b
    }

    function max3(a,b,c)
    {
        return max(a,max(b,c))
    }

    RowLayout{
        id : cc
        anchors.bottom : parent.bottom
        anchors.bottomMargin:4
        anchors.topMargin:4

        ColumnLayout
        {
            id: provideList
            width:100
        }

        ColumnLayout
        {
            id: propertyList
            width:200
        }

        ColumnLayout
        {
            id: requireList
            width:100

        }
}

    function addProvide(name)
    {
        var c = Qt.createComponent("ProvideElement.qml");
        c.createObject(provideList, {"id":name,"name":name});
    }

    function clone(main)
    {
        var c = Qt.createComponent("A.qml");
        clone = c.createObject(main, {});

        /////////////////////////////////////////////////////////
        // for(int i = 0; i < provideList.chidren.length; i++) //
        // {                                                   //
        //     provideList.chidren[0];                         //
        // }                                                   //
        /////////////////////////////////////////////////////////

    }

    function addRequire(name)
    {
        var c = Qt.createComponent("RequireElement.qml");
        c.createObject(requireList, {"name":name});
    }

    function addProperties(type, name, value)
    {
        var c = Qt.createComponent("PropertiesValue.qml");
        c.createObject(propertyList, {"type":type, "name":name, "val":value});
    }

    function set_name(name)
    {
        comp_name.text = name
    }

    function set_type(type)
    {
        comp_type.text = type
    }

    function pressAndHold(m) {
        x= m.x+x - width/2
        y= m.y+y - height/2

    }

    Rectangle{

        height:50
        color:"grey"
        anchors.top:parent.top
        anchors.left:parent.left
        anchors.right:parent.right

        MouseArea {
            anchors.fill: parent

            Component.onCompleted: positionChanged.connect(comp.pressAndHold)
        }

        Text {
            id:comp_name
            anchors.centerIn: parent
            text: "COMP_NAME"
        }

        Text {
            id:comp_type
            anchors.top: comp_name.bottom
            anchors.horizontalCenter : comp_name.horizontalCenter
            text: "TYPE"
        }
    }
}
