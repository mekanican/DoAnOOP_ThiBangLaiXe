import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

Item {

    Layout.fillWidth: true
    Rectangle {
        id: ques
        width: parent.width
        height: 200
        anchors.top: parent.top
        Button {
            text: "abc"
        }
    }
    Rectangle { //
        width: 300
        height: 100
        color: "red"
        anchors.top: ques.bottom
        Button {
            text: "xyz"
        }
    }
    Rectangle {
        width: parent.width
        height: 200
        color: "green"
        anchors.bottom: parent.bottom
        Rectangle {
            width: parent.width / 3
            height: parent.height * 0.34
            anchors.top: parent.top
            anchors.left: parent.left
            Text {
                text: "x1"
            }
        }

        Rectangle {
            width: parent.width / 3
            height: parent.height * 0.34
            anchors.top: parent.top
            anchors.right: parent.right
            Text {
                text: "x2"
            }
        }

        Rectangle {
            width: parent.width / 3
            height: parent.height * 0.34
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            Text {
                text: "x3"
            }
        }

        Rectangle {
            width: parent.width / 3
            height: parent.height * 0.34
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            Text {
                text: "x4"
            }
        }
    }

}
