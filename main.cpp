#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "EncryptorViewModel.h"
#include "AdvancedEncryptorViewModel.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<EncryptorViewModel>("MyViewModels", 1, 0, "EncryptorViewModel");
    qmlRegisterType<AdvancedEncryptorViewModel>("MyViewModels", 1, 0, "AdvancedEncryptorViewModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
