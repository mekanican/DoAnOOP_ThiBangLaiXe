import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.12

Item {
    Row {
        anchors.centerIn: parent
        spacing: 20
        Column {
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                visible: temp.isDone
                text: "Chúc mừng bạn đã hoàn thành bài thi với số điểm " + temp.correctAnswer +
                      " trong thời gian " + (backend.getTime() - counter.value) + "s"
            }

            CheckBox {
                anchors.left : parent.left
                //anchors.horizontalCenter: parent.horizontalCenter
                id: cb1
                visible: backend.isPractice();
                text: "50 / 50"
            }
            CheckBox {
                //anchors.horizontalCenter: parent.horizontalCenter
                anchors.left : parent.left
                id: cb2
                visible: backend.isPractice();
                text: "Đảo thứ tự câu hỏi"
            }
            CheckBox {
                anchors.left: parent.left
                id: cb3
                visible: backend.isPractice();
                text: "Đảo thứ tự câu trả lời"
            }
            CheckBox {
                anchors.left: parent.left
                id: cb4
                visible: backend.isPractice();
                text: "Tập luyện theo chủ đề"
            }
            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                Material.background: Material.Teal
                width: 100
                height: 50
                Text {
                    anchors.centerIn: parent
                    text: "Bắt đầu"
                }
                onClicked: {
                    backend.StartClick(cb1.checkState === Qt.Checked,
                                       cb2.checkState === Qt.Checked,
                                       cb3.checkState === Qt.Checked,
                                       cb4.checkState === Qt.Checked,
                                       cb4_1.checkState === Qt.Checked,
                                       cb4_2.checkState === Qt.Checked,
                                       cb4_3.checkState === Qt.Checked,
                                       cb4_4.checkState === Qt.Checked,
                                       cb4_5.checkState === Qt.Checked,
                                       cb4_6.checkState === Qt.Checked,
                                       cb4_7.checkState === Qt.Checked);
                    stackView.push("playground.qml");
                    if (!backend.isPractice()) {
                        counter.value = backend.getTime()
                        counter.visible = true
                        temp.isDone = false
                    }
                }
            }
        }
        Column {
            CheckBox {
                anchors.left: parent.left
                id: cb4_1
                visible: cb4.checkState === Qt.Checked
                text: "Khái niệm và quy tắc"

            }
            CheckBox {
                anchors.left: parent.left
                id: cb4_2
                visible: cb4.checkState === Qt.Checked
                text: "Nghiệp vụ vận tải"
            }
            CheckBox {
                anchors.left: parent.left
                id: cb4_3
                visible: cb4.checkState === Qt.Checked
                text: "Văn hóa và đạo đức"
            }
            CheckBox {
                anchors.left: parent.left
                id: cb4_4
                visible: cb4.checkState === Qt.Checked
                text: "Kỹ thuật lái xe"
            }
            CheckBox {
                anchors.left: parent.left
                id: cb4_5
                visible: cb4.checkState === Qt.Checked
                text: "Cấu tạo sửa chữa"
            }
            CheckBox {
                anchors.left: parent.left
                id: cb4_6
                visible: cb4.checkState === Qt.Checked
                text: "Biển báo đường bộ"
            }
            CheckBox {
                anchors.left: parent.left
                id: cb4_7
                visible: cb4.checkState === Qt.Checked
                text: "Sa hình"
            }
        }
    }
}
