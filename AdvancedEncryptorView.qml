import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import MyViewModels 1.0

Item {
    implicitWidth: 400
    implicitHeight: 820

    AdvancedEncryptorViewModel {
        id: viewModel
        text: textEdit.text
        selectedKey: keyEdit.text
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 8
        Label {
            Layout.fillWidth: true
            text: "Мегашифратор-4000"
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
            text: viewModel.text
            selectByMouse: true
        }

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: 16
        }

        Button {
            text: "Сгенерировать ключи"
            Layout.alignment: Qt.AlignHCenter
            onClicked: viewModel.generateKeys()
        }

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: 16
        }

        Label {
            Layout.fillWidth: true
            text: "Равнозначные ключи"
        }
        ListView {
            id: keyList
            model: viewModel.keys
            clip: true
            Layout.fillWidth: true
            Layout.preferredHeight: 10 * 30
            Rectangle {
                anchors.fill: parent
                border.color: "#e0e0e0"
                border.width: 1
                z: -100
            }
            delegate: Item {
                width: keyList.width
                height: 30
                Rectangle {
                    color: "#e0e0e0"
                    width: parent.width
                    height: 1
                    anchors.bottom: parent.bottom
                }
                RowLayout {
                    anchors.fill: parent
                    Item {Layout.preferredWidth: 8}
                    Label {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        verticalAlignment: "AlignVCenter"
                        text: modelData.key
                    }
                    Button {
                        Layout.topMargin: 1
                        Layout.bottomMargin: 2
                        Layout.fillHeight: true
                        Layout.preferredWidth: 30
                        text: "⏎"
                        onClicked: keyEdit.text = modelData.key
                    }
                }
            }
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
            text: viewModel.selectedKey
            selectByMouse: true
        }

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: 16
        }

        Button {
            text: "Зашифровать"
            Layout.alignment: Qt.AlignHCenter
            onClicked: viewModel.encrypt()
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
            text: viewModel.encryptedText
        }

        Button {
            text: "Переместить в текст"
            Layout.alignment: Qt.AlignHCenter
            onClicked: textEdit.text = encryptedTextView.text
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
