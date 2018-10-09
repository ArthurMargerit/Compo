import QtQuick 2.0
import QtQuick.Controls 1.4

Canvas {
        id: cnv
        width:1000
        height:1000

        contextType: "2d"
        property var a
        property var ap
        property var b
        property var br

        property var c
        property var cp
        property var d
        property var dr

        function link(comp_from, provide, comp_to, require)
        {
          a = comp_from
          b = comp_to
          ap = provide
          br = require

        }

        function link2(comp_from, provide, comp_to, require)
        {
          c = comp_from
          d = comp_to
          cp = provide
          dr= require

        }

        Path {
            id: myPath
            startX: ap.x + a.x + ap.width /2
            startY: ap.y + a.y + ap.height /2

            PathCurve { x: br.x + b.x + br.width /2 ;
                        y: br.y + b.y + br.height /2 }
        }

        Path {
            id: myPath2
            startX: cp.x + c.x + cp.width /2
            startY: cp.y + c.y + cp.height /2

            PathCurve { x: dr.x + d.x + dr.width /2 ;
                        y: dr.y + d.y + dr.height /2 }
        }

        onPaint: {
            context.lineWidth= 5;
            context.path = myPath;
            context.stroke();

            context.lineWidth= 5;
            context.path = myPath2;
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
