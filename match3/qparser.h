#ifndef QPARSER_H
#define QPARSER_H

#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QVector>
#include <QObject>
class Qparser: public QObject
{
public:
    Qparser(QObject *parent = 0);
    ~Qparser();

    int getWidth()const;
    int getHeighth()const;
    int getMinScore()const;
    QVector<int> getTypes()const;
    int getElementScore()const;
    int getMaxMoves()const;

    void fillFromFile();

private:
    int m_width;
    int m_height;
    int m_maxMoves;
    int m_minScore;
    int m_elementScore;
    QVector<int> m_types;
};

#endif // QPARSER_H
