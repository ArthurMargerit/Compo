import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id:comp

    A{
      id:lap
      x:000
      y:600
     }

    A{
      id:lap1
      x:000
      y:000
     }

     LinkManager
     {
      id:lapin
     }

 Component.onCompleted:
 {
            lap1.addProvide("P1")
            lap1.addProvide("P2")
            lap1.addProvide("P3")

            lap1.addRequire("R1")
            lap1.addRequire("R2")
            lap1.addRequire("R3")

            lap.addProvide("P1")
            lap.addProvide("P2")
            lap.addProvide("P3")

            lap.addRequire("R1")
            lap.addRequire("R2")
            lap.addRequire("R3")

            lapin.link(lap.prov.children[0], lap1.req.children[0]);
  }
        

}



