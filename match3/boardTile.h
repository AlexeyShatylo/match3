#ifndef boardtile_H
#define boardtile_H

#include <QObject>
class boardTile : public QObject
{
    Q_PROPERTY(int type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(double tileOpacity READ getTileOpacity WRITE setTileOpacity NOTIFY tileOpacityChanged)
    Q_OBJECT
public:
    explicit boardTile(QObject *parent = 0);
    boardTile(int type, double opacity);
    int getType() const;
    void setType(int type);
    void setTileOpacity(double opacity);
    double getTileOpacity() const;
private:
    int m_type;
    double m_opacity;
signals:
    void typeChanged();
    void tileOpacityChanged();
public slots:
};

#endif // boardtile_H
