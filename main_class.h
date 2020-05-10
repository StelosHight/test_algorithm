#ifndef MAIN_CLASS_H
#define MAIN_CLASS_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QScopedPointer>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QLabel>
#include <my_scene.h>
#include <my_gview.h>

struct Coord{
    int x;
    int y;
};

class main_class: public QObject
{
    Q_OBJECT
public:
    main_class();
    ~main_class();
    QList<my_gview *> get_views();
    QList<QLabel *> get_labels();

private:
    my_gview *main_view;
    my_gview *timer_view;
    my_gview *sup_view;

    my_scene *main_scene;
    my_scene *timer_scene;
    my_scene *sup_scene;

    QList<QLabel*> labels;

    QList<QGraphicsLineItem*> timers_line;

    QList<Coord> coords;
    QTimer *timer;
    int cur_iter;
private slots:
    void update();
    void resize_timer(const QSize& size);
};

#endif // MAIN_CLASS_H
