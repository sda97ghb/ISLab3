#include "KeyManager.h"


KeyManager::KeyManager(QByteArray key) :
    m_key(key)
{}

QList<QByteArray> KeyManager::keys() {
    QList<QByteArray> result;
    for (int i = 0; i < 10; ++ i)
        result.append(generateKey(m_key, i));
    return result;
}

QByteArray KeyManager::extractKey(QByteArray rawKey) {
    char counter = rawKey.at(0);
    QByteArray tail = rawKey.right(rawKey.length() - 1);
    return xorKey(tail, counter);
}

QByteArray KeyManager::generateKey(QByteArray key, int counter) {
    QByteArray result;
    result.append(char(0x30 + counter));
    result.append(xorKey(key, char(counter)));
    return result;
}

QByteArray KeyManager::xorKey(QByteArray key, char counter) {
    QByteArray result;
    for (int i = 0, iMax = key.length(); i < iMax; ++ i)
        result.append(char(key.at(i) ^ counter));
    return result;
}
