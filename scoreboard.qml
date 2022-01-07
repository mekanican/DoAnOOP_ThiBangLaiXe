import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4
Item {
    property var columns: [ "name", "score", "timetaken", "date" ]
    property var datas: [  ]

    TableView {
        id: tableView
        model: datas
        implicitHeight: 500
        implicitWidth: 500
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Component {
        id: columnComponent
        TableViewColumn {width: 125}
    }

    function toUpperCase(c) { return c.toUpperCase(); }
    function capitalize(str) { return str.replace(/^./, toUpperCase); }

    function addColumn(name) {
        tableView.addColumn(columnComponent.createObject(tableView, { role: name, title: capitalize(name) } ) );
    }

    function reload() {
        datas = []
        var response
        response = backend.scoreboardReq();
        var lines = response.split("===")
        for (let i = 0; i < lines.length; i++) {
            var values = lines[i].split("///")
            datas.push({
                           name: values[0],
                           score: values[1],
                           timetaken: values[2],
                           date: values[3]
                       })
        }
        tableView.model = datas;
    }

    Component.onCompleted: {
        columns.forEach(addColumn)
        // Loading data from backend
        reload();
    }

    Button {
        id: goBack
        anchors.top: parent.top
        anchors.left: parent.left

        Material.background: Material.Teal
        Text {
            anchors.centerIn: parent
            text: "\u21E0"
            font.pointSize: 22
        }
        onClicked: {
            backend.prevScoreboard();
            reload()
        }
    }
    Button {
        id: goForward
        anchors.top: parent.top
        anchors.right: parent.right
        Material.background: Material.Teal
        Text {
            anchors.centerIn: parent
            text: "\u21E2"
            font.pointSize: 22
        }
        onClicked: {
            //tip._tip = ""
            //backend.clickForward()
            backend.nextScoreboard();
            reload();
        }
    }

    Row {
        id: typeBar
        anchors.top : parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "A1"
                font.pointSize: 14
            }

            onClicked: {
                backend.A1Click()
                reload();
            }
        }

        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "A2"
                font.pointSize: 14
            }

            onClicked: {
                backend.A2Click()
                reload();
            }
        }
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "A3"
                font.pointSize: 14
            }

            onClicked: {
                backend.A3Click()
                reload();
            }
        }
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "A4"
                font.pointSize: 14
            }

            onClicked: {
                backend.A4Click()
                reload();
            }
        }
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "B1"
                font.pointSize: 14
            }

            onClicked: {
                backend.B1Click()
                reload();
            }
        }
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "B2"
                font.pointSize: 14
            }

            onClicked: {
                backend.B2Click()
                reload();
            }
        }
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "C"
                font.pointSize: 14
            }

            onClicked: {
                backend.CClick()
                reload();
            }
        }
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "D"
                font.pointSize: 14
            }

            onClicked: {
                backend.DClick()
                reload();
            }
        }
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "E"
                font.pointSize: 14
            }

            onClicked: {
                backend.EClick()
                reload();
            }
        }
        Button {
            width: 40
            Text {
                anchors.centerIn: parent
                text: "F"
                font.pointSize: 14
            }

            onClicked: {
                backend.FClick()
                reload();
            }
        }



    }

}
