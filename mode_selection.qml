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
        text: qsTr("Chọn chế độ")
    }
    Row {
        anchors.centerIn: parent
        spacing: 20
        Button {
            width: 250
            height: 250
            Material.background:(Material.Lime)
            Text {
                anchors.centerIn: parent
                text: "Thi thử"
                font.pointSize: 16
            }
            onClicked: {
                backend.ExClick()
                stackView.push("option_page.qml")
                title_.text = ""
            }
        }
        Button {
            width: 250
            height: 250
            Material.background:(Material.Indigo)
            Text {
                anchors.centerIn: parent
                text: "Tập luyện"
                font.pointSize: 16
            }
            onClicked: {
                backend.PrClick()
                stackView.push("option_page.qml")
                title_.text = ""
            }
        }
    }
}
