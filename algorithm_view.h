#ifndef ALGORITHM_VIEW_H
#define ALGORITHM_VIEW_H

#include <QGraphicsItem>

struct Coord{
    int x;
    int y;
};

class algorithm_view : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    algorithm_view(int x, int y, QObject *parent = nullptr);
    ~algorithm_view();
    void do_magic();
    void set_coords(int x, int y);
private:
    Coord coord_mid;
    QList<int> steps_action;
    int step;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // ALGORITHM_VIEW_H
