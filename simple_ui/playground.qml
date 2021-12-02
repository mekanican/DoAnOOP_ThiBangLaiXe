import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

import io.question 1.0

Item {

    BackEndQuestion {
        id: backend
    }

    Layout.fillWidth: true
    Rectangle {
        id: ques
        width: parent.width
        height: 100
        anchors.top: parent.top
        Text {
            anchors.centerIn: parent
            text: "Question area: " + backend.c
        }
    }
    Image { //
        anchors.top: ques.bottom
        anchors.horizontalCenter: parent.horizontalCenter
//        width: 300
//        height: 100
//        color: "red"
        source: "images.jpeg"
    }
    Button {
        id: goBack
        anchors.top: ques.bottom
        anchors.left: ques.left
        Material.background: Material.Orange
        Text {
            anchors.centerIn: parent
            text: "\u21E0"
            font.pointSize: 22
        }
    }
    Button {
        id: goForward
        anchors.top: ques.bottom
        anchors.right: ques.right
        Material.background: Material.Orange
        Text {
            anchors.centerIn: parent
            text: "\u21E2"
            font.pointSize: 22
        }
    }

    Rectangle {
        width: parent.width
        height: 200
        Material.background: Material.BlueGrey
        anchors.bottom: parent.bottom
        Button {
            width: parent.width / 2.2
            height: parent.height * 0.41
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 12
            anchors.leftMargin: 12
            Material.background: Material.LightBlue
            Material.elevation: 6
            Text {
                anchors.centerIn: parent;
                text: "Cau 1." + backend.c1
                font.pointSize: 12
            }
        }

        Button {
            width: parent.width / 2.2
            height: parent.height * 0.41
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.topMargin: 12
            Material.background: Material.LightBlue
            Material.elevation: 6
            Text {
                anchors.centerIn: parent
                text: "Cau 2." + backend.c2
                font.pointSize: 12
            }
            onClicked: {
                if (backend.c1Click()) {
                    Material.background = Material.Red
                }
            }
        }

        Button {
            width: parent.width / 2.2
            height: parent.height * 0.41
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.leftMargin: 12
            anchors.bottomMargin: 12
            Material.background: Material.LightBlue
            Material.elevation: 6
            Text {
                anchors.centerIn: parent
                text: "Cau 3." + backend.c3
                font.pointSize: 12
            }
        }

        Button {
            width: parent.width / 2.2
            height: parent.height * 0.41
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.bottomMargin: 12
            Material.background: Material.LightBlue
            Material.elevation: 6
            Text {
                anchors.centerIn: parent
                text: "Cau 4." + backend.c4
                font.pointSize: 12
            }
        }
    }

}
