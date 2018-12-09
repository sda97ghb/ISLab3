#include "Encryptor.h"
#include "EncryptorViewModel.h"

#include <QDebug>

EncryptorViewModel::EncryptorViewModel(QObject *parent) : QObject(parent) {

}

QString EncryptorViewModel::text() const {
    return m_text;
}

QString EncryptorViewModel::key() const {
    return m_key;
}

QString EncryptorViewModel::encryptedText() const {
    return m_encryptedText;
}

void EncryptorViewModel::encrypt() {
    auto setEncryptedText = [=](QString encryptedText) {
        m_encryptedText = encryptedText;
        emit encryptedTextChanged(m_encryptedText);
    };
    try {
        QByteArray encrypted = Encryptor::encrypt(
                                   QByteArray::fromPercentEncoding(m_text.toUtf8()),
                                   QByteArray::fromPercentEncoding(m_key.toUtf8()));
        setEncryptedText(encrypted.toPercentEncoding());
    } catch (std::logic_error& e) {
        setEncryptedText(e.what());
    }
}

void EncryptorViewModel::generateKey() {
    QByteArray key = Encryptor::generateKeyOfLength(QByteArray::fromPercentEncoding(m_text.toUtf8()).length());
    setKey(key.toPercentEncoding());
}

void EncryptorViewModel::setText(QString text) {
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(m_text);
}

void EncryptorViewModel::setKey(QString key) {
    if (m_key == key)
        return;

    m_key = key;
    emit keyChanged(m_key);
}
