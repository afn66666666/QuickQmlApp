import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.9
import QtQuick.Layouts 1.9

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListView{
        id: listView
        anchors.fill: parent
        model: listModel
        delegate: Rectangle {
            height: 60
            width: ListView.view.width
            color: "lightgrey"
            border.color: "black"

            Text {
                anchors.centerIn: parent
                text: model.text
            }
        }
    }

    ListModel {
        id: listModel
        ListElement {
            text : "a"
        }
    }
}


