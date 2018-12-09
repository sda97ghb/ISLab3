#pragma once

#include <QByteArray>

class Encryptor {
public:
    static QByteArray generateKeyOfLength(int length);
    static QByteArray encrypt(QByteArray text, QByteArray key);
};
