import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQml.Models 2.1
import QtQuick.Layouts 1.0
import QtQuick 2.0
ApplicationWindow {
    id:root
    visible: true
    width: 1000
    height:1000
    menuBar: MenuBar{
        Menu{
            title: "Menu"
            MenuItem {
                text: "New game"
                shortcut: "Ctrl+N"

            }
            MenuItem {
                text: "Exit"
                shortcut: "Ctrl+Q"
                onTriggered: Qt.quit()
            }
        }
    }
    statusBar: StatusBar{
        RowLayout{
            anchors.fill: parent
            Label{text: "Score: "+dndGrid.model.score}
            Label{text: "Turns left: "+ dndGrid.model.steps}
        }
    }
    Rectangle {
        id:mainRect
        anchors.fill: parent
        color: "lightgreen"
        Component {
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
                    opacity: index < (dndGrid.model.getHeight())*(dndGrid.model.getWidth()) ? 1:0
                    MouseArea {
                        id:rectMouse
                        anchors.fill: parent
                        hoverEnabled: true;
                        onPressed: {
                            game(index);
                        }
                    }
                }
            }
        }
        GridView {
            id: dndGrid
            verticalLayoutDirection: GridView.BottomToTop
            anchors.fill: parent
            anchors.margins: 10
            interactive: false
            cellWidth: (root.width/dndGrid.model.getWidth())-5
            cellHeight: (root.height/dndGrid.model.getHeight())-5
            model:dataModel
            delegate: dndDelegate
            move: Transition {
                id:myTran
                onRunningChanged: {
                    if (!myTran.running) {
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
    function game(index) {

        var moved  = dndGrid.model.doMovement(index);

        if(dndGrid.model.matching()) {
            dndGrid.model.setSteps();
        }
    }
}







