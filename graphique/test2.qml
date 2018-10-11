import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id:comp

    A{
        x:000
        y:000

        Component.onCompleted:
        {
            addRequire("lion1")
        }
    }

    A{
        x:000
        y:300

        Component.onCompleted:
        {
            addProvide("lion1")
        }
    }

    A{
        x:000
        y:600

        Component.onCompleted:
        {
            addProperties("lion1")
        }
    }

    A{
        id :mem
        x:600
        y:400




        Component.onCompleted: {

            addProvide("lapin1")
            addProvide("lapin3")
            addProvide("lapin2")

            addProperties("int","a","10")
            addProperties("int","a","10")
            addProperties("int","a","10")
            addProperties("int","a","10")

            addRequire("lion1")

            clone(comp)
        }
    }

}



