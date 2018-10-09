import QtQuick 2.0
import QtQuick.Controls 1.4

Canvas {
        id: cnv
        width:1000
        height:1000

        contextType: "2d"
        property var a;
        property var b;

        Path {
            id: myPath
            startX: a.p1.x + a.x + a.p1.width /2
            startY: a.p1.y + a.y + a.p1.height /2

            PathCurve { x: b.r1.x + b.x + b.r1.width /2 ;
                        y: b.r1.y + b.y + b.r1.height /2 }

        }

        onPaint: {
            context.lineWidth= 5;
            context.path = myPath;
            context.stroke();
        }

        Timer {
            interval: 10
            running: true
            repeat: true
            onTriggered: {
                var ctx = parent.getContext("2d");
                ctx.clearRect(0,0,parent.width, parent.height);
                parent.requestPaint();
            }
        }
    }
