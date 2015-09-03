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
                onTriggered: gameGrid.model.newGame()
            }
            MenuItem {
                text: "Exit"
                shortcut: "Ctrl+Q"
                onTriggered: Qt.quit()
            }
        }
    }
    statusBar: StatusBar {
        RowLayout {
            anchors.fill: parent
            Label { text: "Score: "+gameGrid.model.score }
            Label { text: "Turns left: "+ gameGrid.model.steps }
        }
    }
    Rectangle {
        id:mainRect
        anchors.fill: parent
        color: "lightgreen"
        Component {
            id: gameDelegate
            Item {
                id: wrapper
                width: gameGrid.cellWidth
                height: gameGrid.cellHeight
                Image {
                    id: cellRect
                    anchors.centerIn: parent
                    Text { text: tileType}
                    width: gameGrid.cellWidth*0.8
                    height: gameGrid.cellHeight*0.8
                    source: gameGrid.model.getSource(tileType)
                    opacity: index < (gameGrid.model.getHeight())*(gameGrid.model.getWidth()) ? 1:0
                    MouseArea {
                        id:rectMouse
                        anchors.fill: parent
                        onPressed: {
                            gameGrid.model.doMovement(index);
                            if(gameGrid.model.isMatched()) {
                                gameGrid.model.setSteps(1)
                            }
                        }
                        enabled: !myTran.running
                    }
                }
            }
        }
        GridView {
            id: gameGrid
            verticalLayoutDirection: GridView.BottomToTop
            anchors.fill: parent
            anchors.margins: 10
            interactive: false
            cellWidth: (root.width/gameGrid.model.getWidth()) - 5
            cellHeight: (root.height/gameGrid.model.getHeight())-5
            model:dataModel
            delegate: gameDelegate
            move: Transition {
                id: myTran
                SequentialAnimation {
                    PauseAnimation {duration: (((myTran.ViewTransition.index + 1 - myTran.ViewTransition.targetIndexes[0])) * 50) }
                    NumberAnimation { properties: "x,y"; duration: 1000; easing.type: Easing.OutBounce }
                    NumberAnimation { properties: "cellRect.opacity"; duration: 500; easing.type: Easing.OutBounce }
                }
                onRunningChanged: {
                    if(!myTran.running) {
                        gameGrid.model.matching()
                    }
                }
            }
            displaced:  Transition{ NumberAnimation { properties: "y"; duration: 500; easing.type: Easing.OutBounce }}
            moveDisplaced: {myTran}
            add: {myTran}
        }
    }
}







