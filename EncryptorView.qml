import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import MyViewModels 1.0

Item {
    implicitWidth: 100//360
    implicitHeight: 470

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
            text: "Мегашифратор-3000"
            font.pointSize: 22
            font.bold: true
        }
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
        RowLayout {
            Layout.fillWidth: true
            Layout.preferredHeight: keyEdit.height
            TextField {
                id: keyEdit
                Layout.fillWidth: true
                placeholderText: "Введите ключ"
                text: encryptorViewModel.key
                selectByMouse: true
            }
            Button {
                text: "Случайный ключ"
                onClicked: encryptorViewModel.generateKey()
            }
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
            id: encryptedTextView
            Layout.fillWidth: true
            placeholderText: "Здесь будет зашифрованный текст"
            readOnly: true
            selectByMouse: true
            text: encryptorViewModel.encryptedText
        }
        ColumnLayout {
            Layout.fillWidth: true
            Layout.preferredHeight: encryptedToTextButton.height
//            Item{Layout.fillWidth: true}
            Button {
                id: encryptedToTextButton
                text: "Переместить в текст"
                onClicked: textEdit.text = encryptedTextView.text
            }
            Button {
                text: "Переместить в ключ"
                onClicked: keyEdit.text = encryptedTextView.text
            }
//            Item{Layout.fillWidth: true}
        }
        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
