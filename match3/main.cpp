#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qtile.h>
#include <QQuickView>
#include <qmatchtreelist.h>
#include "qparser.h"
#include <QQmlContext>
#include <QTime>

int main(int argc, char *argv[])
{
    qsrand(static_cast<uint>(QTime::currentTime().msec()));
    QGuiApplication app(argc, argv);
    Qparser myParser;
    QMatchTreeList myModel(myParser.getMinScore(),myParser.getMaxMoves(), myParser.getHeighth(),myParser.getElementScore(), myParser.getWidth(),myParser.getTypes(),0);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataModel", &myModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
