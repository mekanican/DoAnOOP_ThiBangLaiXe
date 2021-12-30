import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Dialogs 1.2

Item {
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20

        font.pointSize: 22
        text: qsTr("Chọn loại bằng cần thi / Luyện tập")
    }
    Row {
        anchors.centerIn: parent
        spacing: 10
        Rectangle {
            border.color: Material.color(Material.LightBlue)
            color: "transparent"
            height: 250
            width: 250
            Grid {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                columns: 2
                spacing: 10
                Button {
                    Material.background: Material.LightBlue; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "A1"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.A1Click()
                }
                Button {
                    Material.background: Material.LightBlue; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "A2"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.A2Click()
                }
                Button {
                    Material.background: Material.LightBlue; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "A3"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.A3Click()
                }
                Button {
                    Material.background: Material.LightBlue; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "A4"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.A4Click()
                }
            }
        }
        Rectangle {
            border.color: Material.color(Material.Green)
            color: "transparent"
            height: 250
            width: 250
            Row {
                anchors.centerIn: parent
                spacing: 10
                Button {
                    Material.background: Material.Green; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "B1"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.B1Click()
                }
                Button {
                    Material.background: Material.Green; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "B2"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.B2Click()
                }
            }
        }
        Rectangle {
            border.color: Material.color(Material.Orange)
            color: "transparent"
            height: 250
            width: 250
            Grid {
                anchors.centerIn: parent
                columns: 2
                spacing: 10
                Button {
                    Material.background: Material.Orange; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "C"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.CClick()
                }
                Button {
                    Material.background: Material.Orange; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "D"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.DClick()
                }
                Button {
                    Material.background: Material.Orange; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "E"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.EClick()
                }
                Button {
                    Material.background: Material.Orange; width: 75; height: 75
                    Text {
                        anchors.centerIn: parent
                        text: "F"
                        font.bold: true
                        font.pointSize: 20
                    }
                    onClicked: backend.FClick()
                }
            }
        }
    }
}
