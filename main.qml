import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Window 2.2

Window {
    id: mainWindow
    width: 1024
    height: 200
    visible: true

    TextField {
        id: inputField
        anchors.horizontalCenter: parent.horizontalCenter
        width: 1000
        height: 40
        text: "123"
        onAccepted: focus = false
        Keys.onEscapePressed: undo()
    }

    Row {
        id: keyRow1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: inputField.bottom
        anchors.topMargin: 20
        Button {
            id: button1
            text: qsTr("1")
            onClicked: keyEmitter.emitKey(Qt.Key_1)
        }
        Button {
            id: button2
            text: qsTr("2")
            onClicked: keyEmitter.emitKey(Qt.Key_2)
        }
        Button {
            id: button3
            text: qsTr("3")
            onClicked: keyEmitter.emitKey(Qt.Key_3)
        }
        Button {
            id: button4
            text: qsTr("4")
            onClicked: keyEmitter.emitKey(Qt.Key_4)
        }
        Button {
            id: button5
            text: qsTr("5")
            onClicked: keyEmitter.emitKey(Qt.Key_5)
        }
    }
    Row {
        id: keyRow2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: keyRow1.bottom
        Button {
            id: buttonBack
            text: qsTr("DEL")
            onClicked: keyEmitter.emitKey(Qt.Key_Backspace)
        }
        Button {
            id: buttonEnter
            text: qsTr("OK")
            onClicked: keyEmitter.emitKey(Qt.Key_Enter)
        }
        Button {
            id: buttonEsc
            text: qsTr("ESC")
            onClicked: keyEmitter.emitKey(Qt.Key_Escape)
        }
    }
}
