import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    Item {
        anchors.fill: parent

        Rectangle {
            id: r
            anchors.centerIn: parent
            width: 600
            height: 400
        }

        Text {
            anchors.fill: r
            id: name
            text: qsTr("Phần mềm hỗ trợ thi lái xe của nhóm 2\nGồm 3 thành viên:\n- A\n- B\n- C")
            font.family: "Open sans"
            font.pointSize: 17
        }
    }

}
