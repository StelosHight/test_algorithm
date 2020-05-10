#ifndef MY_SCENE_H
#define MY_SCENE_H

#include <QGraphicsScene>

class my_scene: public QGraphicsScene
{
public:
    my_scene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MY_SCENE_H
