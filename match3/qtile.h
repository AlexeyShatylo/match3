#ifndef QTILE_H
#define QTILE_H

#include <QObject>
class QTile : public QObject
{
    Q_PROPERTY(int type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(double tileOpacity READ getTileOpacity WRITE setTileOpacity NOTIFY tileOpacityChanged)
    Q_OBJECT
public:
    explicit QTile(QObject *parent = 0);
    QTile(int type, double opacity);

    void setType(int type);
    void setTileOpacity(double opacity);
    int getType() const;
    double getTileOpacity() const;
private:
    int m_type;
    double m_opacity;
signals:
    void typeChanged();
    void tileOpacityChanged();
public slots:
};

#endif // QTILE_H
