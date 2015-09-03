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
#include <QDebug>

class QMatchTreeList : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int score READ getScore WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(int steps READ getSteps WRITE setSteps NOTIFY stepsChanged)
public:
    QMatchTreeList(QObject* parent = 0);
    QMatchTreeList(int minScore, int maxMoves, int height, int elementScore, int width, QVector<int> types, QObject *parent = 0);
    ~QMatchTreeList();
    QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE int getWidth()const;
    Q_INVOKABLE int getHeight()const;
    Q_INVOKABLE int rowCount(const QModelIndex &parent) const;
    Q_INVOKABLE QString getSource(int type);
    QHash<int, QByteArray> roleNames() const;
    int getRandomNumber(const int Min, const int Max);
    void fillRandomly();
    void remove();
    void fillMatches(int index);
    void deleteMatches();
    void fillSecondBoard();
    void setScore(int machedTiles);
    bool findMatchOnVertical();
    bool findMatchOnHorizontal();
    bool create();
    bool doPath(int index);
    Q_INVOKABLE bool doMovement(int index);
    Q_INVOKABLE bool matching();
    Q_INVOKABLE bool isMatched();
    Q_INVOKABLE bool backSwap();
    Q_INVOKABLE int getType(int index);
    Q_INVOKABLE int getScore()const;
    Q_INVOKABLE int getSteps()const;
    Q_INVOKABLE void victory();
    Q_INVOKABLE void newGame();
    enum cellRoles{tileTypeRole = Qt::UserRole+1, tileOpacityRole = Qt::UserRole+2};
private:
    int m_minScore;
    int m_maxMoves;
    int m_elementScore;
    int m_width;
    int m_height;
    int m_totalScore;
    int m_leftSteps;
    bool isProgressMade;
    bool isGame;
    QTile* m_tile;
    QVector<QTile*> m_list;
    QVector<int> m_types;
    QVector<int> m_totalMatches;
    QVector<int> m_path;
    QVector<int> m_backSwapPath;
signals:
    void scoreChanged();
    void stepsChanged();
    void signalOfVictory();
    void signalOfDefeat();
public slots:
    void setSteps(int SuccesfulStep);
};



#endif // QMATCHTREELIST_H
