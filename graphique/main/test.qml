import QtQuick 2.3
import QtQuick.Controls 1.4

Rectangle {
    Rectangle
    {
        id:linktome
        color:"grey"
        width: 10; height: 10
        x:200
        y:200
    }


    Rectangle {
        id:main
        width: 100; height: 100
        color: "lightsteelblue"

        Rectangle{
            id: ina
            width: 20
            height: parent.height
            color:"green"
            anchors.right: parent.left
            anchors.rightMargin:5
        }


        Column{
            spacing:10
            id:out
            width: 20
            height: parent.height

            anchors.left: parent.right
            anchors.leftMargin: 5

            Rectangle {
                color: "yellow"
                width: 20
                height: 20

                id:linkfromme

                MouseArea {
                    anchors.fill: parent
                    drag.target: parent;
                }
            }

        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent;
            drag.threshold:20
            drag.filterChildren: true

            id:mam
            Component.onCompleted: {
                console.log("lapin")
                mam.positionChanged.connect(bb.a)
            }
        }

    }

    Button
    {
        text:"re"
        id:bb
        onClicked:a()
        function a()
        {
            console.log("fefrech")
            canva.clear_canvas()
            canva.requestPaint()
            console.log(linktome.x)

        }
    }


    Canvas {
        id:canva
        width: parent.width
        height: parent.height

        contextType: "2d"

        function clear_canvas() {
            var ctx = getContext("2d");
            ctx.reset();
            canva.requestPaint();
        }

        Path {
            id: myPath
            startX: linkfromme.x + main.x + out.x + linkfromme.width/2
            startY: linkfromme.y + main.y + out.y + linkfromme.height/2
            PathLine { id:last
                       x: linktome.x
                       y: linktome.y }
        }

        onPaint: {
            context.strokeStyle = Qt.rgba(.4,.6,.8);
            context.path = myPath;
            context.stroke();
        }
    }
}
