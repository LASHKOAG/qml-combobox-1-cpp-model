#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QQuickStyle>
#include "pagecontroller.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Используем стиль Qt Quick Controls
    //QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;

    // Создание экземпляра контроллера
    PageController pageController;

    // Регистрация контроллера в QML
    engine.rootContext()->setContextProperty("pageController", &pageController);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
