
import QtQuick 2.5
import QtQuick.Window 2.2

import QuickFlux 1.0

Rectangle {
    visible: true
    color: "transparent"

    anchors.fill: parent

    Rectangle {
        id: popupsRoot
        objectName: "popupsRoot"
        anchors.fill: parent
        color: "transparent"
    }

    Rectangle {
        id: popupsRoot1
        objectName: "popupsRoot1"
        anchors.fill: parent
        color: UserInfoStore.ui.testColor
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            AppEvents.changeNickname("new nickname")
            AppEvents.changeBalance("new balance")
        }
    }
}
