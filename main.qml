import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
//    minimumWidth: 400
//    maximumWidth: 400
    minimumHeight: [470, 910][theSwipeView.currentIndex]
    maximumHeight: [470, 910][theSwipeView.currentIndex]
    title: qsTr("Hello World")

    header: TabBar {
        id: theTabBar
        TabButton {
            text: "Простое шифрование"
        }
        TabButton {
            text: "Расширенное шифрование"
        }
        currentIndex: theSwipeView.currentIndex
    }

    SwipeView {
        id: theSwipeView
        currentIndex: theTabBar.currentIndex
        anchors.fill: parent
        ScrollView {
            contentWidth: -1
            EncryptorView {
                width: theSwipeView.width
            }
        }
        ScrollView {
            contentWidth: -1
//            ScrollBar.vertical.policy: ScrollBar.AlwaysOn

            AdvancedEncryptorView {
                width: theSwipeView.width
            }
        }
    }
}
