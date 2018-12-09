#pragma once

#include <QObject>
#include <QVariantList>

class AdvancedEncryptorViewModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QVariantList keys READ keys NOTIFY keysChanged)
    Q_PROPERTY(QString selectedKey READ selectedKey WRITE setSelectedKey NOTIFY selectedKeyChanged)
    Q_PROPERTY(QString encryptedText READ encryptedText NOTIFY encryptedTextChanged)

public:
    explicit AdvancedEncryptorViewModel(QObject *parent = nullptr);

    QString text() const;
    QVariantList keys() const;
    QString selectedKey() const;
    QString encryptedText() const;

signals:
    void textChanged(QString text);
    void keysChanged(QVariantList keys);
    void selectedKeyChanged(QString selectedKey);
    void encryptedTextChanged(QString encryptedText);

public slots:
    void generateKeys();
    void encrypt();

    void saveKeysToFile(QString filename);

    void setText(QString text);
    void setSelectedKey(QString selectedKey);

private:
    QString m_text;
    QVariantList m_keys;
    QString m_selectedKey;
    QString m_encryptedText;
};
