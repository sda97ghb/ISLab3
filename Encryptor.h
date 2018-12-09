#pragma once

#include <QByteArray>

class Encryptor {
public:
    static QByteArray encrypt(QByteArray text, QByteArray key);
};
