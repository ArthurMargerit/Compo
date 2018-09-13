import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
	  width: 1000
	  height: 1000

	  id:dd

	  Rectangle {
	      id: comp
	      width: 100
	      height: 60
	      color: "red"
	      border.width:2
	      border.color: "black"
	      x:500
        y:500


        Canvas {
            width: 1000; height: 1000
            contextType: "2d"

            Path {
                id: myPath
                PathCurve { x: pro1.x; y: pro1.y }
                PathCurve { x: (pro1.x+req1.x)/2; y: pro1.y+50 }
                PathCurve { x: req1.x; y: req1.y }
            }

            onPaint: {
                context.strokeStyle = Qt.rgba(.4,.6,.8);
                context.lineWidth= 4;
                context.path = myPath;
                context.stroke();
            }
        }

	      Rectangle {
	  	      id: pro1

		        anchors.topMargin:5
		        anchors.right: comp.left
		        anchors.top: parent.top
		        anchors.rightMargin: 5
		        
		        width: 10
	  	      height: 10
	  	      color: "green"
		        
		        Text {
		    	      anchors.right: parent.left
			          anchors.rightMargin: 10
	       		    text: "pro1"
	  		    }
		    }

	      Rectangle {
		        id: pro2
	  	      
		        anchors.topMargin:5
	  	      anchors.top: pro1.bottom	  	    
		        anchors.right: comp.left
		        anchors.rightMargin: 5

		        width: 10
	  	      height: 10
	  	      color: "green"

		        Text {
		    	      anchors.right: parent.left
			          anchors.rightMargin: 10
	       		    text: "pro2"
	  		    }

		    }

	      Rectangle {
	  	      id:req1

		        anchors.topMargin:5
	  	      anchors.top: parent.top	  	    
	  	      anchors.left: comp.right
		        anchors.leftMargin: 5
		        
		        width: 10
	  	      height: 10
	  	      color: "blue"
		    	  Text {
			          anchors.left: parent.right
			          anchors.leftMargin: 10
	       		    text: "req1"
	  		    }
		    }

	      Rectangle {
	  	      id:req2
		        anchors.topMargin:5
		        anchors.top: req1.bottom	  	    
	  	      anchors.left: comp.right	  
		        anchors.leftMargin: 5

		        width: 10
	  	      height: 10
	  	      color: "blue"

		    	  Text {
			          anchors.left: parent.right
			          anchors.leftMargin: 10
	       		    text: "req2"
	  		    }

 	      }

	      Text {
            id:comp_name
	          anchors.centerIn: parent
	          text: "COMP_NAME"
	      }
        Text {
	          anchors.top: comp_name.bottom
            anchors.horizontalCenter : comp_name.horizontalCenter
            color:"red"
	          text: "TYPE"
	      }
    }
}

