import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQml.Models 2.1
import QtQuick.Layouts 1.0
import QtQuick 2.0
import QtQuick 2.3
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
                        onPressed:{ dndGrid.model.doMovement(index) }
                        enabled: !myTran.running
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
            cellWidth: (root.width/dndGrid.model.getWidth()) - 5
            cellHeight: (root.height/dndGrid.model.getHeight())-5

            model:dataModel
            delegate: dndDelegate
            move: Transition {
                id: myTran
                SequentialAnimation {
                    PauseAnimation {duration: ((myTran.ViewTransition.index+1 - myTran.ViewTransition.targetIndexes[0])) *30 }
                    NumberAnimation { properties: "x,y"; duration: 100; easing.type: Easing.OutBounce }
                    NumberAnimation { properties: "cellRect.opacity"; duration: 100; easing.type: Easing.OutBounce }
                }
                onRunningChanged:
                {
                    if(!myTran.running)
                    {
                        dndGrid.model.matching()
                    }
                }
            }
            displaced:  { myTran }
            moveDisplaced: { myTran }
        }
    }


}







