#include "qtile.h"

QTile::QTile(QObject *parent) : QObject(parent)
{

}
QTile::QTile(int type, double opacity) :m_type(type),m_opacity(opacity)
{

}
int QTile::getType()const
{
    return m_type;
}

double QTile::getTileOpacity() const
{
    return m_opacity;
}

void QTile::setType(int type)
{
    m_type = type;
    emit typeChanged();
}

void QTile::setTileOpacity(double opacity)
{
    m_opacity = opacity;
    emit tileOpacityChanged();
}

