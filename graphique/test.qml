import QtQuick 2.11
import QtQuick.Controls 1.4


Rectangle {
    id: window

        MouseArea
        {
            anchors.fill: parent
            property var scaleValue: 1.05

            property real px : 0
            property real py : 0

            property real oriX : 0
            property real oriY : 0

            function pc(m)
            {
                //console.log("from " +px+ "," +py+ " to "+ m.x+","+m.y)
                sca.origin.x = oriX + (m.x-px)*3 / sca.xScale
                sca.origin.y = oriY + (m.y-py)*3 / sca.yScale
            }

            function oc(m){
                px = m.x
                py = m.y
                oriX = sca.origin.x
                oriY = sca.origin.y
            }

            Component.onCompleted: {
                onPressed.connect(oc)

                positionChanged.connect(pc)
            }

            onWheel:{
                if((wheel.angleDelta.y > 0))
                {
                    console.log("in")

                    sca.origin.x = (wheel.x - sca.origin.x ) * scaleValue + sca.origin.x
                    sca.origin.y = (wheel.y - sca.origin.y ) * scaleValue + sca.origin.y

                    sca.xScale *= scaleValue
                    sca.yScale *= scaleValue

                }
                else
                {
                    console.log("out")
                    sca.origin.x = (wheel.x - sca.origin.x)/ scaleValue + sca.origin.x
                    sca.origin.y = (wheel.y -  sca.origin.y)/ scaleValue + sca.origin.y

                    sca.xScale /= scaleValue
                    sca.yScale /= scaleValue
                }

                console.log("Scale:"+sca.xScale+","+sca.yScale)
                console.log("position:"+sca.origin.x+","+sca.origin.y)
            }
        }


    Rectangle {
	      id:dd
        width : 1000
        height: 1000

        border.width:5
        border.color: "black"

        transform: Scale { id:sca; origin.x: 10; origin.y: 10; xScale: 1.0}


        A {
            id: lap
            x: 400
            y: 100

        }

        A {
            id: lap1
            x: 100
            y: 300

        }

        A {
            id: lap2
            x: 100
            y: 600

        }

        LinkManager
        {
            id:lapin
            Component.onCompleted: {
                console.log("lapin")
                link(lap.p1, lap1.r1 )
                link(lap.p2, lap1.r2 )
                link(lap2.p1, lap1.r1 )
                link(lap2.p2, lap.r2 )

            }
        }


    }

}
