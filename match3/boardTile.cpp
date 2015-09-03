#include "boardTile.h"

boardTile::boardTile(QObject *parent) : QObject(parent)
{

}
boardTile::boardTile(int type, double opacity) :m_type(type),m_opacity(opacity)
{

}
int boardTile::getType()const
{
    return m_type;
}

double boardTile::getTileOpacity() const
{
    return m_opacity;
}

void boardTile::setType(int type)
{
    m_type = type;
    emit typeChanged();
}

void boardTile::setTileOpacity(double opacity)
{
    m_opacity = opacity;
    emit tileOpacityChanged();
}

