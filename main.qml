import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import MyViewModels 1.0

Window {
    visible: true
    width: 400
    height: 480
    title: qsTr("Hello World")

    EncryptorViewModel {
        id: encryptorViewModel
        text: textEdit.text
        key: keyEdit.text
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 8
        Label {
            Layout.fillWidth: true
            text: "Текст"
        }
        TextField {
            id: textEdit
            Layout.fillWidth: true
            placeholderText: "Введите шифруемый текст"
            text: encryptorViewModel.text
            selectByMouse: true
        }
        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: 8
        }
        Label {
            Layout.fillWidth: true
            text: "Ключ"
        }
        TextField {
            id: keyEdit
            Layout.fillWidth: true
            placeholderText: "Введите ключ"
            text: encryptorViewModel.key
            selectByMouse: true
        }

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: 16
        }

        Button {
            text: "Зашифровать"
            Layout.alignment: Qt.AlignHCenter
            onClicked: encryptorViewModel.encrypt()
        }

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: 16
        }

        Label {
            Layout.fillWidth: true
            text: "Зашифрованный текст"
        }
        TextField {
            Layout.fillWidth: true
            placeholderText: "Здесь будет зашифрованный текст"
            readOnly: true
            selectByMouse: true
            text: encryptorViewModel.encryptedText
        }
        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
