#ifndef ENCRYPTORVIEWMODEL_H
#define ENCRYPTORVIEWMODEL_H

#include <QObject>

class EncryptorViewModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString key READ key WRITE setKey NOTIFY keyChanged)
    Q_PROPERTY(QString encryptedText READ encryptedText NOTIFY encryptedTextChanged)

public:
    explicit EncryptorViewModel(QObject *parent = nullptr);

    QString text() const;
    QString key() const;
    QString encryptedText() const;

signals:
    void textChanged(QString text);
    void keyChanged(QString key);
    void encryptedTextChanged(QString encryptedText);

public slots:
    void encrypt();

    void generateKey();

    void setText(QString text);
    void setKey(QString key);

private:
    QString m_text;
    QString m_key;
    QString m_encryptedText;
};

#endif // ENCRYPTORVIEWMODEL_H
