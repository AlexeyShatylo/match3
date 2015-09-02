#include "qparser.h"

Qparser::Qparser(QObject *parent): QObject(parent)
{
    fillFromFile();
}
void Qparser::fillFromFile()
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
int Qparser::getWidth() const
{
    return m_width;
}
int Qparser::getHeighth() const
{
    return m_height;
}
int Qparser::getMinScore() const
{
    return m_minScore;
}

int Qparser::getElementScore() const
{
    return m_elementScore;
}

int Qparser::getMaxMoves() const
{
    return m_maxMoves;
}

QVector<int> Qparser::getTypes() const
{
    return m_types;
}

Qparser::~Qparser()
{

}



