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
            text: qsTr("Phan mem ho tro thi lai xe den tu nhom 2\nGom 3 thanh vien:\n- abc\n- xyz\n- mno")
            font.family: "Open sans"
            font.pointSize: 17
        }
    }

}
