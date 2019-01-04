import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id:main


    A{
      id:lap
      x:000
      y:300
     }

    A{
      id:lap1
      x:600
      y:300
     }

     LinkManager
     {
      id:lapin
     }

 Component.onCompleted:
 {
            lap1.addProvide("P1")

            lap.addRequire("R1")
            lap.addRequire("R2")
            lap.addRequire("R3")

            lapin.link(lap.req.children[0], lap1.prov.children[0]);
            lapin.link(lap.req.children[1], lap1.prov.children[0]);
            lapin.link(lap.req.children[2], lap1.prov.children[0]);
  }
        

}



