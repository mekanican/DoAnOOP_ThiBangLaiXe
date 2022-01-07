import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.12
//import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.12
import io.qt.examples.backend 1.0

ApplicationWindow {

    Material.theme:  Material.Light
    Material.accent: Material.Purple

    id: root
    width: 800
    height: 600
    visible: true
    title: qsTr("Application")

    BackEnd {
        id: backend
    }

    header: ToolBar {
        contentHeight: toolButton.implicitHeight
        Text {
            anchors.centerIn: parent
            id: title_
            text: qsTr("Phần mềm hỗ trợ thi bằng lái xe")
            font.family: "Open sans"
            font.pointSize: 22
        }
        Text {
            id: counter
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 20
            property int value: 0
            text: Math.floor(value / 60).toString()
                  + ":"
                  + ((value % 60) < 10 ? "0" : "")
                  + (value % 60).toString()
            font.pointSize: 20
            color: Material.color(Material.Red)
            visible: false;
        }

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u25BD"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    if (counter.visible == true) {
                        counter.visible = false;
                        temp.isDone = true;
                        temp.correctAnswer = backend.getCorrect()
                        backend.addToScoreboard(backend.getTime() - counter.value)
                    }
                    stackView.pop()
                    if (stackView.depth == 1) {
                        title_.text = "Phần mềm hỗ trợ thi bằng lái xe"
                        layer1.visible = true
                    }
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "empty.qml"
        //focus: true
        anchors.fill: parent
    }

    Item {
        id: layer1
        anchors.fill: parent
        Column {
            spacing: 30
            anchors.centerIn: parent

            Button {
                id: b1
                height: 70
                width: 100
                text: "Đăng nhập"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    title_.text = qsTr("Đăng nhập")
                    stackView.push("login.qml")
                    layer1.visible = false
                }
                Material.background: Material.Teal

            }

            Button {
                height: 70
                width: 100
                text: "Giới thiệu"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    title_.text = qsTr("Giới thiệu")
                    stackView.push("about.qml")
                    layer1.visible = false
                }
                Material.background: Material.Teal
            }

            Button {
                height: 70
                width: 100
                text: "Bảng điểm"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    title_.text = qsTr("Bảng điểm")
                    stackView.push("scoreboard.qml")
                    layer1.visible = false
                }
                Material.background: Material.Teal
            }


            Button {
                height: 70
                width: 100
                text: "Thoát"
                bottomPadding: 0
                topPadding: 0
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    Qt.callLater(Qt.quit)
                }
                Material.background: Material.Red
            }
        }
    }

//    Text {
//        id: realName
//        text: ""
//        enabled: false
//    }
    Item {
        id: temp
        visible: false
        property int correctAnswer : 0
        property bool isDone : false
    }

}
