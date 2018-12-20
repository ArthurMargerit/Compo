import QtQuick 2.0
import QtQuick.Controls 1.4

Canvas {
        id: cnv
        anchors.fill: parent

        contextType: "2d"

        Item {
           id: linkList
           
        }


        function link(provide,require)
        {
          var c = Qt.createComponent("PathProToReq.qml");
          if (c.status == Component.Ready)
             var b = c.createObject(linkList, {"from_require": require , "to_component": provide});

             console.log("link on "+b);
        }
        
        
        onPaint: {

          for(var i = 0; i < linkList.children.length; i++){
            context.lineWidth= 3;
            context.path = linkList.children[i].path;
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
