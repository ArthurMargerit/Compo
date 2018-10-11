import QtQuick 2.0
import QtQuick.Controls 1.4

Canvas {
        id: cnv
        anchors.fill: parent

        contextType: "2d"

        Item {
           id: lapinisA
           
        }


        function link(provide,require)
        {
          var c = Qt.createComponent("PathProToReq.qml");
          if (c.status == Component.Ready)
             var t = c.createObject(lapinisA, {"from_require": require , "to_component": provide});

             console.log(t)
        }
        
        
        onPaint: {

          for(var i = 0; i < lapinisA.children.length; i++){
            context.lineWidth= 5;
            context.path = lapinisA.children[i].path;
            context.stroke();
            }

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
