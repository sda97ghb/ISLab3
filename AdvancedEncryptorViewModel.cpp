#include "AdvancedEncryptorViewModel.h"
#include "Encryptor.h"
#include "KeyManager.h"

#include <QDebug>

AdvancedEncryptorViewModel::AdvancedEncryptorViewModel(QObject *parent) : QObject(parent) {
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
    m_keys.append(QVariantMap {{"key", ""}});
}

QString AdvancedEncryptorViewModel::text() const {
    return m_text;
}

QVariantList AdvancedEncryptorViewModel::keys() const {
    return m_keys;
}

QString AdvancedEncryptorViewModel::selectedKey() const {
    return m_selectedKey;
}

QString AdvancedEncryptorViewModel::encryptedText() const {
    return m_encryptedText;
}

void AdvancedEncryptorViewModel::generateKeys() {
    QByteArray key = Encryptor::generateKeyOfLength(QByteArray::fromPercentEncoding(m_text.toUtf8()).length());
    QList<QByteArray> keys = KeyManager(key).keys();

    m_keys.clear();
    while (!keys.isEmpty()) {
        m_keys.append(QVariantMap {{"key", keys.takeAt(rand() % keys.size()).toPercentEncoding()}});
    }
    emit keysChanged(m_keys);

    setSelectedKey(m_keys.first().toMap().value("key").toString());
}

void AdvancedEncryptorViewModel::encrypt() {
    QByteArray rawKey = QByteArray::fromPercentEncoding(m_selectedKey.toUtf8());
    QByteArray key = KeyManager::extractKey(rawKey);

    auto setEncryptedText = [=](QString encryptedText) {
        m_encryptedText = encryptedText;
        emit encryptedTextChanged(m_encryptedText);
    };
    try {
        QByteArray text = QByteArray::fromPercentEncoding(m_text.toUtf8());
        QByteArray encrypted = Encryptor::encrypt(text, key);
        setEncryptedText(encrypted.toPercentEncoding());
    } catch (std::logic_error& e) {
        setEncryptedText(e.what());
    }
}

void AdvancedEncryptorViewModel::saveKeysToFile(QString filename) {
    filename = QUrl(filename).toLocalFile();
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Невозможно записать в файл";
        return;
    }
    QTextStream stream(&file);
    for (auto key : m_keys)
        stream << key.toMap().value("key").toString() << "\n";
    stream.flush();
    file.flush();
    file.close();
}

void AdvancedEncryptorViewModel::setText(QString text) {
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(m_text);
}

void AdvancedEncryptorViewModel::setSelectedKey(QString selectedKey) {
    if (m_selectedKey == selectedKey)
        return;

    m_selectedKey = selectedKey;
    emit selectedKeyChanged(m_selectedKey);
}
