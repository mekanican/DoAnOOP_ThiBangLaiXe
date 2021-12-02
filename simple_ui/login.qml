import QtQuick 2.0
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0
import QtQuick.Layouts 1.12

Item {
    BackEnd {
        id: backend
    }
    Column {
        anchors.centerIn: parent
        TextField {
            width: 200
            id: rname
            text: backend.realName
            placeholderText: qsTr("Realname")
            KeyNavigation.tab: login
            onTextChanged: backend.realName = text
            visible: false
        }
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

        RadioButton {
            anchors.horizontalCenter: parent.horizontalCenter
            id: res
            text: "Dang ky"
            onClicked: {
                rname.visible = true;
            }
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            id: go
            text: "Dang nhap"
            onClicked: {
                backend.buttonClick()
                if (backend.isLogin === true) {
                    stackView.pop()
                    stackView.push("selection.qml")
                    realName.text = backend.realName
                    realName.enabled = true
                }
            }
        }


    }
}
