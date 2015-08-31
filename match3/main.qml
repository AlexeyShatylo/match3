import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQml.Models 2.1
ApplicationWindow {
    id:root
    visible: true
    width: 1000
    height: 1000
    MenuBar{

        Menu {
            title: ("Menu")
            MenuSeparator{
                visible:  true
            }
            MenuItem{
                text: ("New game")
                shortcut: "Ctrl+n"
                onTriggered: dndGrid.model.fillRandomly();
            }
            MenuItem{
                text: ("Exit")
                shortcut: "Ctrl+q"
                onTriggered: Qt.quit();
            }
        }
        Menu{
            title: ("Info")
            MenuItem {
                text: ("About")
            }
        }
    }
    Rectangle {
        id:mainRect
        anchors.fill: parent
        color: "lightgreen"

        Component{
            id: dndDelegate
            Item {
                id: wrapper
                width: dndGrid.cellWidth
                height: dndGrid.cellHeight

                Image {
                    id: cellRect
                    anchors.centerIn: parent
                    width: dndGrid.cellWidth*0.8
                    height: dndGrid.cellHeight*0.8
                    source: dndGrid.model.getSource(tileType)
                  //  opacity: index < (dndGrid.model.getHeight())*(dndGrid.model.getWidth()) ? 1:0
                    Text {
                        id: idTile
                        text: index  + "\n type:" +tileType
                    }
                    MouseArea {
                        id:rectMouse
                        anchors.fill: parent
                        hoverEnabled: true;
                        onPressed:
                        {
                            dndGrid.model.doMovement(index);
                            //dndGrid.model.matching();
                        }

                    }
                }
            }
        }
        GridView{
            id: dndGrid
            interactive: true
            verticalLayoutDirection: GridView.BottomToTop

            anchors.fill: parent
            anchors.margins: 10
            cellWidth: (root.width/dndGrid.model.getWidth())-5
            cellHeight: (root.height/dndGrid.model.getHeight())-5
            model:dataModel
            delegate: dndDelegate
            move: Transition {
                id:myTran

                onRunningChanged: {
                    if (!myTran.running) {
                        console.log()
                        dndGrid.model.matching();
                    }
                }
                ParallelAnimation {
                    NumberAnimation {
                        property: "x"
                        duration: 2000;
                    }
                    NumberAnimation {
                        property: "y"
                        duration: 2000;
                    }
                }
            }
            moveDisplaced: myTran
        }
    }

}





