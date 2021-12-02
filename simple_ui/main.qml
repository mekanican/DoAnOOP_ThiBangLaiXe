import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.12
//import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.12
import io.qt.examples.backend 1.0

ApplicationWindow {

    Material.theme:  Material.Dark
    Material.accent: Material.Purple

    id: root
    width: 800
    height: 600
    visible: true
    title: qsTr("Your name ?")

    header: ToolBar {
        contentHeight: toolButton.implicitHeight
        Text {
            anchors.centerIn: parent
            id: title_
            text: qsTr("Phần mềm hỗ trợ thi bằng lái xe")
            font.family: "Open sans"
            font.pointSize: 22
        }
        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u25BD"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
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
                text: "Dang nhap"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    title_.text = qsTr("Dang nhap")
                    stackView.push("login.qml")
                    layer1.visible = false
                }
                Material.background: Material.Teal

            }

            Button {
                height: 70
                width: 100
                text: "Gioi Thieu"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    title_.text = qsTr("Gioi thieu")
                    stackView.push("about.qml")
                    layer1.visible = false
                }
                Material.background: Material.Teal
            }

            Button {
                height: 70
                width: 100
                text: "Thoat"
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

    Text {
        id: realName
        text: ""
        enabled: false
    }


}
