#include "algorithm_view.h"
#include <QPainter>
#include <QtMath>

algorithm_view::algorithm_view(int x, int y, QObject *parent) : QObject(parent), QGraphicsItem()
{
    step = 0;
    coord_mid.x = x;
    coord_mid.y = y;
}

algorithm_view::~algorithm_view()
{

}

void algorithm_view::do_magic()
{
    step++;
    switch (step){
        case 1:
        steps_action.push_back(1);
        break;
        case 2:
        steps_action.push_back(2);
        break;
        default:
        int old_size = steps_action.size();
        int count_invert = qPow(2, step-3);

        for (int i = 0; i < count_invert; i++)
            steps_action.push_back(steps_action[i] * -1);
        for (int i = count_invert; i < old_size; i++)
            steps_action.push_back(steps_action[i]);

        break;
    }
}

QRectF algorithm_view::boundingRect() const
{
    return QRectF(0, 0, 20, 20);
}

void algorithm_view::set_coords(int x, int y)
{
    coord_mid.x = x;
    coord_mid.y = y;
}

void algorithm_view::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Coord coord = coord_mid;
    int x_new, y_new;
    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    for(int i = 0; i < steps_action.size(); i++)
    {
        x_new = coord.x;
        y_new = coord.y;
        switch (steps_action[i])
        {
        case 1:
            x_new += 20;
            break;
        case -1:
            x_new -= 20;
            break;
        case 2:
            y_new += 20;
            break;
        case -2:
            y_new -= 20;
            break;
        }
        painter->drawLine(coord.x, coord.y, x_new, y_new);
        coord.x = x_new;
        coord.y = y_new;
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
