import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Dialogs 1.2

Item {

//    MessageDialog {
//        id: messageDialog
//        property int correct
//        title: "Hết giờ!"
//        text: "Bạn làm đúng được " + correct + " câu."
//        onAccepted: {
//            Qt.quit()
//        }
//    }

    MessageDialog {
        Component.onCompleted: _tip = ""
        id: tip
        title: "Tip!"
        property string _tip
        text: _tip
    }

    Layout.fillWidth: true
    Rectangle {
        id: ques
        width: parent.width
        height: 100
        anchors.top: parent.top
        Timer {
            id: t
            interval: 1000; running: true; repeat: true
            onTriggered: {
//                q.text = "OUT OF TIME"
                counter.value--;
                if (counter.value === 0) {
//                    q.text = "OUT OF TIME"
                    stop();
                     temp.correctAnswer = backend.getCorrect();
                    temp.isDone = true;
                    counter.visible = false;
                    stackView.pop();
                    backend.addToScoreboard(backend.getTime())
                }

            }
        }

        Text {
            id: q
            anchors.centerIn: parent
            text: "Câu hỏi: " + backend.c
            width: parent.width
            height: parent.height
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
    Image { //
        anchors.top: ques.bottom
        anchors.horizontalCenter: parent.horizontalCenter
//        width: 300
//        height: 100
//        color: "red"
        source: backend.path
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
        onClicked: {
            tip._tip = ""
            backend.clickPrevious()
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
        onClicked: {
            tip._tip = ""
            backend.clickForward()
        }
    }

    Rectangle {
        Component.onCompleted: backend.update();
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
            Material.background: backend.a1 === 0 ? Material.LightBlue :
                                                    (backend.a1 === -1 ? Material.Red :
                                                                         Material.Green)

            Material.elevation: 6
            Text {
                anchors.centerIn: parent;
                width: parent.width
                height: parent.height
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: backend.c1
                font.pointSize: 10
            }
            onClicked: {
                backend.c1Click();
                if (tip._tip === "") {
                    tip._tip = backend.getTip();
                    if (tip._tip.length > 0) {
                        tip.open()
                    }
                }
            }
        }

        Button {
            width: parent.width / 2.2
            height: parent.height * 0.41
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.topMargin: 12
            Material.background: backend.a2 === 0 ? Material.LightBlue :
                                                    (backend.a2 === -1 ? Material.Red
                                                                       : Material.Green)
            Material.elevation: 6
            Text {
                anchors.centerIn: parent
                width: parent.width
                height: parent.height
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: backend.c2
                font.pointSize: 10
            }
            onClicked: {
                backend.c2Click();
                if (tip._tip === "") {
                    tip._tip = backend.getTip();
                    if (tip._tip.length > 0) {
                        tip.open()
                    }
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
            Material.background: backend.a3 === 0 ? Material.LightBlue :
                                                    (backend.a3 === -1 ? Material.Red
                                                                       : Material.Green)
            Material.elevation: 6
            Text {
                anchors.centerIn: parent
                width: parent.width
                height: parent.height
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: backend.c3
                font.pointSize: 10
            }
            onClicked: {
                backend.c3Click();
                if (tip._tip === "") {
                    tip._tip = backend.getTip();
                    if (tip._tip.length > 0) {
                        tip.open()
                    }
                }
            }
        }

        Button {
            width: parent.width / 2.2
            height: parent.height * 0.41
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: 12
            anchors.bottomMargin: 12
            Material.background: backend.a4 === 0 ? Material.LightBlue :
                                                    (backend.a4 === -1 ? Material.Red
                                                                       : Material.Green)
            Material.elevation: 6
            Text {
                anchors.fill: parent
                width: parent.width
                height: parent.height
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: backend.c4
                font.pointSize: 10
            }
            onClicked: {
                backend.c4Click();
                if (tip._tip === "") {
                    tip._tip = backend.getTip();
                    if (tip._tip.length > 0) {
                        tip.open()
                    }
                }
            }
        }
    }

}
