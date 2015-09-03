#include "inputDataParser.h"

inputDataParser::inputDataParser(QObject *parent): QObject(parent)
{
    fillFromFile();
}
void inputDataParser::fillFromFile()
{
        QFile file("inputData.json");
        file.open(QIODevice::ReadOnly);
        QByteArray rawData = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(rawData));
        QJsonObject json = doc.object();
        m_width = json["width"].toInt();
        m_height = json["height"].toInt();
        m_elementScore = json["elementScore"].toInt();
        m_minScore = json["minScore"].toInt();
        m_maxMoves = json["maxMoves"].toInt();
        QJsonArray q = json["types"].toArray();
        for(int i = 0; i < q.size(); i++) {
              m_types.append(q[i].toInt());
        }
}
int inputDataParser::getWidth() const
{
    return m_width;
}
int inputDataParser::getHeighth() const
{
    return m_height;
}
int inputDataParser::getMinScore() const
{
    return m_minScore;
}

int inputDataParser::getElementScore() const
{
    return m_elementScore;
}

int inputDataParser::getMaxMoves() const
{
    return m_maxMoves;
}

QVector<int> inputDataParser::getTypes() const
{
    return m_types;
}

inputDataParser::~inputDataParser()
{

}



