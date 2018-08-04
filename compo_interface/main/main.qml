//import related modules
import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
//window containing the application

ApplicationWindow {

    //title of the application
    title: qsTr("Hello World")
    width: 640
    height: 480

    //menu containing two menu items
    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("&save")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("&Exit")
                onTriggered: Qt.quit();
            }
        }

        Menu {
            title: qsTr("&View")
            MenuItem {
                text: qsTr("&Type")
                onTriggered: console.log(text);
            }
            MenuItem {
                text: qsTr("&Struct")
                onTriggered: console.log(text);
            }
            MenuItem {
                text: qsTr("&Interface")
                onTriggered: console.log(text);
            }
            MenuItem {
                text: qsTr("&Composant")
                onTriggered: console.log(text);
            }
            MenuItem {
                text: qsTr("&Link")
                onTriggered: console.log(text);
            }
            MenuItem {
                text: qsTr("&Deploiment")
                onTriggered: console.log(text);
            }
        }

        Menu {
            title: qsTr("&Tool")
            MenuItem {
                text: qsTr("&Check")
                onTriggered: console.log(text);
            }

            MenuItem {
                text: qsTr("&View Code")
                onTriggered: console.log(text);
            }

            MenuItem {
                text: qsTr("&Generate")
                onTriggered: console.log(text);
            }
        }


        Menu {
            title: qsTr("&Help")
            MenuItem {
                text: qsTr("&License")
                onTriggered: console.log(text);
            }
            MenuItem {
                text: qsTr("&Git")
                onTriggered: console.log(text);
            }
            MenuItem {
                text: qsTr("&Info")
                onTriggered: console.log(text);
            }
        }
    }

TabView {
   width:parent.width
   height:parent.height
        
    
    Tab {
        title: "Deploiment"
        DeploimentCreator {}
    }
    Tab {
        title: "Link"
        Rectangle { color: "green" }
    }

    Tab {
        title: "Composant"
        Rectangle { color: "green" }
    }

    Tab {
        title: "Interface"
        Rectangle { color: "green" }
    }


    Tab {
        title: "Struct"
        Rectangle { color: "blue" }
    }
    Tab {
        title: "Types"
        TypeCreator{}
    }

}

}
