#include "matchTreeList.h"

MatchTreeList::MatchTreeList(QObject *parent): QAbstractListModel(parent)
{

}
MatchTreeList::MatchTreeList(int minScore, int maxMoves, int height, int elementScore,int width, QVector<int> types, QObject *parent): QAbstractListModel(parent), m_types(types), m_minScore(minScore),m_maxMoves(maxMoves),m_elementScore(elementScore),m_width(width), m_height(height)

{
    m_isGame = false;
    create();
    matching();
    m_path.clear();
    m_totalScore = 0;
    m_isGame = true;
    m_leftSteps = maxMoves;
}
MatchTreeList::~MatchTreeList()
{
    remove();
}
QVariant MatchTreeList::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size()){
        return QVariant();
    }
    const boardTile* m_tile = m_list[index.row()];
    if(role == tileTypeRole) {
        return m_tile->getType();
    } else if(role == tileOpacityRole) {
        return m_tile->getTileOpacity();
    }
    return 0;
}
int MatchTreeList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  m_list.size();
}
QHash<int, QByteArray> MatchTreeList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[tileTypeRole] = "tileType";
    roles[tileOpacityRole] = "tileOpacity";
    return roles;
}
bool MatchTreeList::doMovement(int index)
{
    m_isProgressMade = false;
    if(doPath(index)) {
        if (int(m_path[0] / m_width) == int(m_path[1] / m_width) && !m_isProgressMade) {
            if(m_path[0] - m_path[1] == - 1 ){
                beginMoveRows(QModelIndex(), m_path[0], m_path[0], QModelIndex(), m_path[0] + 2);
                endMoveRows();
                qSwap(m_list[m_path[0]], m_list[m_path[1]]);
                if(isMatched()){
                    m_isProgressMade = true;
                }
            }
            if(m_path[0] - m_path[1] == 1 && !m_isProgressMade) {
                beginMoveRows(QModelIndex(), m_path[0], m_path[0], QModelIndex(), m_path[0] - 1);
                endMoveRows();
                qSwap(m_list[m_path[0]], m_list[m_path[1]]);
                if(isMatched()){
                    m_isProgressMade = true;
                }
            }
        }
        else {
            if ((m_path[0] - m_path[1]) == - m_width && !m_isProgressMade) {
                beginMoveRows(QModelIndex(), m_path[0], m_path[0], QModelIndex(), m_path[0] + m_width);
                endMoveRows();
                beginMoveRows(QModelIndex(), m_path[1], m_path[1], QModelIndex(), m_path[1] - m_width);
                endMoveRows();
                qSwap(m_list[m_path[0]],m_list[m_path[1]]);
                if(isMatched()) {
                    m_isProgressMade = true;
                }
            }
            if ((m_path[0] - m_path[1]) ==  m_width && !m_isProgressMade) {
                beginMoveRows(QModelIndex(), m_path[1], m_path[1], QModelIndex(), m_path[1] + m_width);
                endMoveRows();
                beginMoveRows(QModelIndex(), m_path[0], m_path[0], QModelIndex(), m_path[0] - m_width);
                endMoveRows();
                qSwap(m_list[m_path[0]], m_list[m_path[1]]);
                if(isMatched()) {
                    m_isProgressMade = true;
                }
            }
        }
        m_path.clear();
    }
    return m_isProgressMade;
}
void MatchTreeList::fillMatches(int index)
{
    int temp = index;
    if(m_totalMatches.isEmpty()) {
        m_totalMatches.append(temp);
    }
    else {
        for(int i = 0; i < m_totalMatches.size(); i++) {
            if(temp != m_totalMatches[i]) {
                if(i == m_totalMatches.size() - 1) {
                    m_totalMatches.append(index);
                }
            }
            else if(temp == m_totalMatches[i]) {
                break;
            }
        }
    }
}
void MatchTreeList::deleteMatches()
{
    if(!m_totalMatches.isEmpty()) {
        std::sort(m_totalMatches.begin(),m_totalMatches.end());
    }
    for (int i = m_totalMatches.size() - 1; i >= 0; i--) {
        for (int j = 0; j < m_height; j++) {
            doMovement(m_totalMatches[i]);
            doMovement(m_totalMatches[i] + m_width);
            m_totalMatches[i] += m_width;
        }
    }
    setScore(m_totalMatches.size());
    fillSecondBoard();
    m_totalMatches.clear();
}
int MatchTreeList::getScore() const
{
    return m_totalScore;
}
void MatchTreeList::setScore(int machedTiles)
{
    m_totalScore += machedTiles * m_elementScore;
    emit scoreChanged();
}
void MatchTreeList::setSteps(int SuccesfulStep)
{
    Q_UNUSED(SuccesfulStep);
    m_leftSteps--;
    emit stepsChanged();
}
bool MatchTreeList::isMatched()
{
    bool isVerticalMatch = findMatchOnVertical();
    bool isHorizontalMatch = findMatchOnHorizontal();
    return isVerticalMatch || isHorizontalMatch;
}
bool MatchTreeList::matching()
{
    if(m_isGame) {
        if(!m_isProgressMade) {
            backSwap();
            m_isProgressMade = true;
            m_backSwapPath.clear();
        }
        if (isMatched()) {
            deleteMatches();
            matching();
            return true;
        }
        else {
            return false;
        }
    }
    if(!m_isGame) {
        if (isMatched()) {
            deleteMatches();
            matching();
            fillSecondBoard();
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}
int MatchTreeList::getType(int index){
    return m_list[index]->getType();
}
bool MatchTreeList::findMatchOnHorizontal()
{
    QVector<int>matchedHorizontal;
    QVector<int>temp;
    for (int i = 0; i < m_height * m_width; i += m_width) {
        for(int j = 0; j < m_width; j++) {
            if (temp.empty()) {
                temp.append(i + j);
            }
            if (m_list[i + j]->getType() == m_list[i + j + 1]->getType() && (int((i + j) / m_width)) == int((i + j + 1) / m_width)) {
                temp.append(i + j + 1 );
            }
            else {
                if (temp.size() >= 3) {
                    matchedHorizontal.append(temp);
                }
                temp.clear();
            }
        }
        if (temp.size() >= 3) {
            matchedHorizontal.append(temp);
        }
        temp.clear();
    }
    for(int i = 0; i < matchedHorizontal.size(); i++) {
        fillMatches(matchedHorizontal[i]);
    }
    return matchedHorizontal.size();
}
bool MatchTreeList::findMatchOnVertical()
{
    QVector<int>matchedVertical;
    QVector<int>temp;
    for(int i = 0; i < m_width; i++) {
        for(int j = 0; j < m_height; j++) {
            if (temp.empty()) {
                temp.append(i + (j * m_width));
            }
            if (m_list[(i + j * m_width)]->getType() == m_list[(i + ( j + 1 ) * m_width)]->getType()) {
                temp.append((i + (j + 1) * m_width ));
            }
            else {
                if (temp.size() > 2) {
                    matchedVertical.append(temp);
                }
                temp.clear();
            }
        }
        temp.clear();
    }
    for(int i = 0; i < matchedVertical.size(); i++)
    {
        fillMatches(matchedVertical[i]);
    }
    return !matchedVertical.isEmpty();
}
void MatchTreeList::fillSecondBoard()
{
    QVector<int> randVect;
    while(randVect.size() < m_width * m_height){
        int  temp = getRandomNumber(0, m_types.size() - 1);
        randVect.append(temp);
    }
    for(int i = m_width; i < randVect.size(); i++) {
        beginRemoveRows(QModelIndex(), i + m_width * m_height, i + m_width * m_height);
        m_list.removeAt(i + m_width * m_height);
        endRemoveRows();
        boardTile* temp = new boardTile();
        beginInsertRows(QModelIndex(), i + m_width * m_height, i + m_width * m_height);
        temp->setType(randVect[i]);
        temp->setTileOpacity(1);
        m_list.insert(i + m_width * m_height, temp);
        endInsertRows();
    }
}
bool MatchTreeList::create ()
{
    m_tile = new boardTile[(2 * m_width * m_height)];
    fillRandomly();
    if(!m_tile) {
        return false;
    }
    for (int i = 0; i < 2 * m_width * m_height; i++) {
        m_list.append(&m_tile[i]);
    }
    matching();
    return true;
}
void MatchTreeList::remove()
{
    delete[] m_tile;
}
int MatchTreeList::getWidth() const
{
    return m_width;
}
int MatchTreeList::getHeight() const
{
    return m_height;
}
QString MatchTreeList::getSource(int type)
{
    switch (type) {
    case 0:
        return "qrc:/img_clock.png";
        break;
    case 1:
        return "qrc:/img_compas.png";
        break;
    case 2:
        return "qrc:/img_lamp.png";
        break;
    case 3:
        return "qrc:/img_tetris.png";
        break;
    case 4:
        return "qrc:/img_vinil.png";
        break;
    default:
        break;
    }
    return "noImage";
}
bool MatchTreeList::doPath(int index)
{
    if(!m_path.size()) {
        m_path.append(index);
    }
    else {
        if(m_path.size() < 2 && m_path[0] != index ) {
            m_path.append(index);
            m_backSwapPath = m_path;
            return true;
        }
    }
    return false;
}
int MatchTreeList::getRandomNumber(const int Min, const int Max)
{
    return ((qrand() % ((Max + 1) - Min)) + Min);
}

int MatchTreeList::getSteps() const
{
    return m_leftSteps;
}
void MatchTreeList::victory()
{
    if(m_totalScore >= m_minScore && m_leftSteps <= m_maxMoves) {
        emit signalOfVictory();
    }
    else {
        emit signalOfDefeat();
    }
}
void MatchTreeList::fillRandomly()
{
    QVector<int> randVect;
    while(randVect.size() < 2 * m_width * m_height) {
        int  temp = getRandomNumber(0, m_types.size() - 1);
        randVect.append(temp);
    }
    for(int i = 0; i < randVect.size(); i++) {
        m_tile[i].setType(randVect[i]);
        m_tile[i].setTileOpacity(1);
    }
}
bool MatchTreeList::backSwap()
{
    int start = m_backSwapPath[1];
    int end = m_backSwapPath[0];
    m_isProgressMade = false;
    if (int(start/m_width) == int(end/m_width) && !m_isProgressMade) {
        if(start - end == -1 ) {
            beginMoveRows(QModelIndex(), start, start, QModelIndex(), start + 2);
            endMoveRows();
            qSwap(m_list[start], m_list[end]);
            m_isProgressMade = true;
        }
        if(start - end == 1 && !m_isProgressMade) {
            beginMoveRows(QModelIndex(), start, start, QModelIndex(), start - 1);
            endMoveRows();
            qSwap(m_list[start], m_list[end]);
            m_isProgressMade = true;
        }
    }
    else {
        if ((start - end) == - m_width && !m_isProgressMade) {
            beginMoveRows(QModelIndex(), start, start, QModelIndex(), start + m_width);
            endMoveRows();
            beginMoveRows(QModelIndex(), end, end, QModelIndex(), end - m_width);
            endMoveRows();
            qSwap(m_list[start],m_list[end]);
            m_isProgressMade = true;
        }
        if ((start - end) ==  m_width && !m_isProgressMade) {
            beginMoveRows(QModelIndex(), end, end, QModelIndex(), end + m_width);
            endMoveRows();
            beginMoveRows(QModelIndex(), start, start, QModelIndex(), start - m_width);
            endMoveRows();
            qSwap(m_list[start], m_list[end]);
            m_isProgressMade = true;
        }
    }
    return m_isProgressMade;
}
void MatchTreeList::newGame()
{
    fillRandomly();
    beginResetModel();
    matching();
    setScore(0);
    fillSecondBoard();
    endResetModel();
    m_leftSteps = m_maxMoves;
    m_isGame = true;
    m_totalScore = 0;
    m_path.clear();
}
