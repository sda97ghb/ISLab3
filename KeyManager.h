#pragma once

#include <QByteArray>
#include <QList>

class KeyManager {
public:
    KeyManager(QByteArray key);

    QList<QByteArray> keys();

    static QByteArray extractKey(QByteArray rawKey);

private:
    QByteArray generateKey(QByteArray key, int counter);
    static QByteArray xorKey(QByteArray key, char counter);

    QByteArray m_key;
};
