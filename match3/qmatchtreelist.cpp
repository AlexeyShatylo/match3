#include "qmatchtreelist.h"
#include <QDebug>

QMatchTreeList::QMatchTreeList(QObject *parent): QAbstractListModel(parent)
{

}
QMatchTreeList::QMatchTreeList(int minScore, int maxMoves, int height, int elementScore,
                               int width, QVector<int> types, QObject *parent):
    QAbstractListModel(parent), m_minScore(minScore),m_maxMoves(maxMoves),
    m_types(types),m_elementScore(elementScore),m_width(width), m_height(height)
{
    create();
    matching();
}
QMatchTreeList::~QMatchTreeList()
{
    remove();
}

QVariant QMatchTreeList::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size()){
        return QVariant();
    }
    const QTile* m_tile = m_list[index.row()];
    if(role == tileTypeRole){
        return m_tile->getType();
    } else if(role == tileOpacityRole) {
        return m_tile->getTileOpacity();
    }
    return 0;
}
int QMatchTreeList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  m_list.size();
}


QHash<int, QByteArray> QMatchTreeList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[tileTypeRole] = "tileType";
    roles[tileOpacityRole] = "tileOpacity";
    return roles;
}
void QMatchTreeList::doMovement(int index)
{
    bool isProgressMade = false;
    if(doPath(index)){
        if (int(m_path[0]/m_width) == int(m_path[1]/m_width) && !isProgressMade) {
            if (m_path[0] - m_path[1] == South || m_path[0] - m_path[1] == North){
                if(m_path[0] - m_path[1] == North){
                    beginMoveRows(QModelIndex(),m_path[0], m_path[0] ,QModelIndex(),m_path[1]+1);
                    qSwap(m_list[m_path[0]],m_list[m_path[1]]);
                    endMoveRows();
                    isProgressMade = true;
                }
                if(m_path[0] - m_path[1] == South && !isProgressMade){
                    beginMoveRows(QModelIndex(),m_path[0], m_path[0] ,QModelIndex(),m_path[1]);
                    qSwap(m_list[m_path[0]],m_list[m_path[1]]);
                    endMoveRows();
                    isProgressMade = true;
                }
            }
        }
        else
        {
            if ((m_path[0]-m_path[1]) ==  - m_width && !isProgressMade){
                    beginMoveRows(QModelIndex(),m_path[0], m_path[0],QModelIndex(),m_path[1]+1);
                    qSwap(m_list[m_path[0]],m_list[m_path[1]]);
                    endMoveRows();
                    beginMoveRows(QModelIndex(),m_path[1] -1, m_path[1] - 1,QModelIndex(),m_path[0]);
                    endMoveRows();
                    isProgressMade = true;
            }
            if ((m_path[0] - m_path[1]) ==  m_width && !isProgressMade) {
                    beginMoveRows(QModelIndex(),m_path[0], m_path[0],QModelIndex(),m_path[1]);
                    qSwap(m_list[m_path[0]], m_list[m_path[1]]);
                    endMoveRows();
                    beginMoveRows(QModelIndex(),m_path[1] + 1, m_path[1] + 1,QModelIndex(),m_path[0] + 1);
                    endMoveRows();
                    isProgressMade = true;
            }
        }
        m_path.clear();
    }
}
bool QMatchTreeList::findMatchOnHorizontal()
{
    QVector<int>matchedHorizontal;
    QVector<int>temp;
    for (int i = 0; i < m_height * m_width; i+= m_width) {
        for(int j = 0; j < m_width - 1; j++) {
            if (temp.empty()) {
                temp.append(i + j);
            }
            if (m_list[i + j]->getType() == m_list[i + j + 1]->getType() && (int((i + j)/m_width)) == int((i + j + 1)/m_width)) {
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

    for(int i = 0; i < matchedHorizontal.size(); i++)
    {
        fillMatches(matchedHorizontal[i]);
    }
    return !matchedHorizontal.isEmpty();
}
void QMatchTreeList::fillMatches(int index)
{
    int temp = index;
    if(m_totalMatches.isEmpty())
    {
        m_totalMatches.append(temp);
    }
    else
    {
        for(int i = 0; i < m_totalMatches.size(); i++)
        {
            if(temp != m_totalMatches[i])
            {
                if(i == m_totalMatches.size()-1)
                {
                    m_totalMatches.append(index);
                }
            }
            else if(temp == m_totalMatches[i])
            {
                break;
            }
        }
    }
}

void QMatchTreeList::deleteMatches()
{
    for (int i = 0; i < m_totalMatches.size(); i++) {
        for (int j = 0; j < m_height; j++) {
            doMovement(m_totalMatches[i]);
            doMovement(m_totalMatches[i] + m_width);
            m_totalMatches[i] += m_width;
        }
        fillSecondBoard();
    }
    m_totalMatches.clear();
}
bool QMatchTreeList::matching()
{
    bool isHorizontalMatch = findMatchOnHorizontal();
    bool isVerticalMatch = findMatchOnVertical();
    if (isVerticalMatch || isHorizontalMatch) {
        deleteMatches();
        matching();
    }
    if (!isVerticalMatch || !isHorizontalMatch)
    {
        m_totalMatches.clear();
        return false;
    }
}

bool QMatchTreeList::findMatchOnVertical()
{
    QVector<int>matchedVertical;
    QVector<int>temp;
    for(int i = 0; i < m_width; i++) {
        for(int j = 0; j < m_height-1; j++) {
            if (temp.empty()) {
                temp.append(i+(j*m_width));
            }
            if (m_list[(i + j*m_width)]->getType() == m_list[(i+(j+1)*m_width)]->getType()) {
                temp.append((i +(j+1)*m_width ));
            }
            else {
                if (temp.size() >= 3) {
                    matchedVertical.append(temp);
                }
                temp.clear();
            }
        }
        if (temp.size() >= 3) {
            matchedVertical.append(temp);
        }
        temp.clear();
    }
    for(int i = 0; i < matchedVertical.size(); i++)
    {
        fillMatches(matchedVertical[i]);
    }
    return !matchedVertical.isEmpty();
}
bool QMatchTreeList::fillSecondBoard()
{
    QVector<int> randVect;
    while(randVect.size() < m_width*m_height){
        int  temp = getRandomNumber(0,m_types.size()-1);
        randVect.append(temp);
    }
    for(int i = m_width; i < randVect.size(); i++){
        beginRemoveRows(QModelIndex(),i+m_width*m_height, i+m_width*m_height);
        m_list.removeAt(i+m_width*m_height);
        endRemoveRows();
        QTile* temp = new QTile();
        beginInsertRows(QModelIndex(),i+m_width*m_height,i+m_width*m_height);
        temp->setType(randVect[i]);
        temp->setTileOpacity(1);
        m_list.insert(i+m_width*m_height, temp);
        endInsertRows();
    }
}
bool QMatchTreeList::create ()
{
    m_tile = new QTile[( 2*m_width*m_height)];
    fillRandomly();
    if(!m_tile){
        return false;
    }
    for (int i = 0; i < 2 *m_width*m_height; i++){
        m_list.append(&m_tile[i]);
    }
        matching();
    return true;
}
void QMatchTreeList::remove()
{
    delete[] m_tile;
}
int QMatchTreeList::getWidth() const
{
    return m_width;
}
int QMatchTreeList::getHeight() const
{
    return m_height;
}

QString QMatchTreeList::getSource(int type)
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
}

bool QMatchTreeList::doPath(int index)
{
    if(m_path.size() < 2)
    {
        if(!m_path.size()){
            m_path.append(index);
        }

        if(m_path[0] != index){
            m_path.append(index);
        }
        if(m_path.size() == 2)
        {
            return true;
        }
    }
    else{
        return false;
    }
}

int QMatchTreeList::getRandomNumber(const int Min, const int Max)
{
    return ((qrand() % ((Max + 1) - Min)) + Min);
}
void QMatchTreeList::fillRandomly()
{
    QVector<int> randVect;
    while(randVect.size() < 2*m_width*m_height){
        int  temp = getRandomNumber(0,m_types.size()-1);
        randVect.append(temp);
    }
    for(int i = 0; i < randVect.size(); i++){
        m_tile[i].setType(randVect[i]);
        m_tile[i].setTileOpacity(1);
    }
}
