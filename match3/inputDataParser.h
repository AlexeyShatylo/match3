#ifndef inputDataParser_H
#define inputDataParser_H
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QVector>
#include <QObject>
class inputDataParser: public QObject
{
public:
    inputDataParser(QObject *parent = 0);
    ~inputDataParser();
    int getWidth()const;
    int getHeighth()const;
    int getMinScore()const;
    int getElementScore()const;
    int getMaxMoves()const;
    QVector<int> getTypes()const;
    void fillFromFile();
private:
    int m_width;
    int m_height;
    int m_maxMoves;
    int m_minScore;
    int m_elementScore;
    QVector<int> m_types;
};

#endif // inputDataParser_H
