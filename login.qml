import QtQuick 2.0
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2

Item {
    MessageDialog {
        id: messageDialog
        property string response
        title: "Thông báo"
        text: response
        onAccepted: {}
    }

    Column {
        anchors.centerIn: parent
        TextField {
            width: 200
            id: login
            text: backend.userName
            placeholderText: qsTr("Username")
            KeyNavigation.tab: password
            onTextChanged: backend.userName = text
        }

        TextField {
            width: 200
            id: password
            text: backend.passWord
            placeholderText: qsTr("Password")
            echoMode: TextInput.Password
            onTextChanged: backend.passWord = text
            KeyNavigation.tab: go
        }

        CheckBox {
            anchors.horizontalCenter: parent.horizontalCenter
            id: res
            text: "Đăng Ký"
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            id: go
            text: "Đăng Nhập"
            onClicked: {
                messageDialog.response = backend.buttonClick(res.checkState === Qt.Checked)
                messageDialog.open();
                messageDialog.Ok;
                if (backend.isLogin === true) {
                    title_.text = "Chào mừng " + backend.realName
                    stackView.pop()
                    stackView.push("type_selection.qml")
//                    counter.value = 240
//                    counter.visible = true
                }
            }
        }


    }
}
