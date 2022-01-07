import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0

Item {
    Item {
        anchors.fill: parent

        Rectangle {
            id: r
            anchors.centerIn: parent
            border.color: Material.color(Material.Teal)
            width: 600
            height: 400
        }

        Text {
            anchors.fill: r
            id: name
            text: qsTr("Phần mềm hỗ trợ thi lái xe của nhóm 2\nGồm 3 thành viên:\n- 20120316 - Nguyễn Hoàng Lâm\n- 20120463 - Nguyễn Lê Duy\n- 20120536 - Võ Trọng Nghĩa")
            font.family: "Open sans"
            font.pointSize: 17
        }
    }

}
