import QtQuick 2.0
import QtQuick.Controls 1.4


Rectangle {
	  width: 1000
	  height: 1000
	  id:dd


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

    LinkManager
    {
        id:lapin
        Component.onCompleted: {
            console.log("lapin")
            link(lap, lap.p1, lap1, lap1.r1 )
            link2(lap, lap.p1, lap1, lap1.r2 )
        }
    }


}

