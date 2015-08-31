#ifndef QMATCHTREELIST_H
#define QMATCHTREELIST_H
#include <QObject>
#include <QAbstractListModel>
#include <QVariant>
#include <QVector>
#include <QString>
#include <QModelIndex>
#include <QJsonDocument>
#include "qtile.h"
#include <QTimer>
#include <iostream>
enum    coord {North = -1, South = 1, East = +4, West = -4};
class QMatchTreeList : public QAbstractListModel
{
    Q_PROPERTY(int score READ getScore WRITE setScore NOTIFY scoreChanged)
    Q_OBJECT
public:
    enum cellRoles{tileTypeRole = Qt::UserRole+1, tileOpacityRole = Qt::UserRole+2};
    QMatchTreeList(QObject* parent = 0);
    QMatchTreeList(int minScore, int maxMoves,
                   int height, int elementScore,
                   int width, QVector<int> types,
                   QObject *parent = 0);
    ~QMatchTreeList();
    QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE int getWidth()const;
    Q_INVOKABLE int getHeight()const;
    Q_INVOKABLE int rowCount(const QModelIndex &parent) const;
    Q_INVOKABLE QString getSource(int type);
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE bool doMovement(int index);

    void remove();
    void fillRandomly();
    bool create();
    Q_INVOKABLE bool findMatchOnVertical();
    Q_INVOKABLE bool findMatchOnHorizontal();
    Q_INVOKABLE void fillMatches(int index);

    void printMatches();
    bool doPath(int index);
    int  getRandomNumber(const int Min, const int Max);

    Q_INVOKABLE bool matching();
    void deleteMatches();

    int getScore()const;
    void setScore(int machedTiles);
    bool fillSecondBoard();
    Q_INVOKABLE int getType(int index);
private:
    int m_minScore;
    int m_maxMoves;
    int m_elementScore;
    int m_width;
    int m_height;
    int m_totalScore;
    QTile* m_tile;

    QVector<QTile*> m_list;
    QVector<int> m_types;
    QVector<int> m_totalMatches;
    QVector<int> m_path;
public slots:

signals:
    void scoreChanged();

};

#endif // QMATCHTREELIST_H
