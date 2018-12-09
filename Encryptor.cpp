#include "Encryptor.h"

QByteArray Encryptor::generateKeyOfLength(int length) {
    QByteArray result;
    for (int i = 0; i < length; ++ i) {
        result.append(char((rand() % 256) - 128));
    }
    return result;
}

QByteArray Encryptor::encrypt(QByteArray text, QByteArray key) {
    if (text.length() != key.length())
        throw std::logic_error("Текст и ключ имеют разную длину");

    QByteArray result;
    for (int i = 0, iMax = text.length(); i < iMax; ++ i) {
        result.append(text.at(i) ^ key.at(i));
    }
    return result;
}
