#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <boardTile.h>
#include <QQuickView>
#include <matchTreeList.h>
#include "inputDataParser.h"
#include <QQmlContext>
#include <QTime>

int main(int argc, char *argv[])
{
    qsrand(static_cast<uint>(QTime::currentTime().msec()));
    QGuiApplication app(argc, argv);
    inputDataParser myParser;
    MatchTreeList myModel(myParser.getMinScore(),myParser.getMaxMoves(), myParser.getHeighth(),myParser.getElementScore(), myParser.getWidth(),myParser.getTypes(),0);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataModel", &myModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
