#ifndef MatchTreeList_H
#define MatchTreeList_H
#include <QObject>
#include <QAbstractListModel>
#include <QVariant>
#include <QVector>
#include <QString>
#include <QModelIndex>
#include <QJsonDocument>
#include "boardTile.h"
#include <QTimer>
#include <QDebug>

class MatchTreeList : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int score READ getScore WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(int performedSteps READ getSteps WRITE setSteps NOTIFY stepsChanged)
public:
    MatchTreeList(QObject* parent = 0);
    MatchTreeList(int minScore, int maxMoves, int height, int elementScore, int width, QVector<int> types, QObject *parent = 0);
    ~MatchTreeList();
    QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE int getWidth()const;
    Q_INVOKABLE int getHeight()const;
    Q_INVOKABLE int rowCount(const QModelIndex &parent) const;
    Q_INVOKABLE QString getSource(int type);
    QHash<int, QByteArray> roleNames() const;
    bool create();
    void remove();
    void fillRandomly();
    void fillMatches(int index);
    void deleteMatches();
    void fillSecondBoard();
    void setScore(int machedTiles);
    int getRandomNumber(const int Min, const int Max);
    bool findMatchOnVertical();
    bool findMatchOnHorizontal();
    bool makeWay(int index);
    Q_INVOKABLE bool doMovement(int index);
    Q_INVOKABLE bool matching();
    Q_INVOKABLE bool isMatched();
    Q_INVOKABLE bool backSwap();
    Q_INVOKABLE int getType(int index) const ;
    Q_INVOKABLE int getScore() const;
    Q_INVOKABLE int getSteps() const;
    Q_INVOKABLE bool isVictory();
    Q_INVOKABLE void newGame();
    Q_INVOKABLE int getMinScore() const;
    Q_INVOKABLE int getMaxMoves() const;
    enum cellRoles{tileTypeRole = Qt::UserRole + 1, tileOpacityRole = Qt::UserRole + 2};
private:
    int m_minScore;
    int m_maxMoves;
    int m_height;
    int m_elementScore;
    int m_width;
    QVector<int> m_types;
    int m_totalScore;
    int m_performedSteps;
    bool m_isSuccessfulStep;
    bool m_isGame;
    QVector<boardTile*> m_list;
    boardTile* m_tile;
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



#endif // MatchTreeList_H
