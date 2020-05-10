#include "main_class.h"
#include <QtMath>

main_class::main_class(): main_scene(new my_scene()), timer_scene(new my_scene()), sup_scene(new my_scene()), timer(new QTimer())
{
    this->main_view = new my_gview();
    this->timer_view = new my_gview();
    this->sup_view = new my_gview();

    cur_iter = 0;

    this->main_view->setScene(main_scene);
    this->timer_view->setScene(timer_scene);
    this->sup_view->setScene(sup_scene);

    connect(timer_view, SIGNAL(ResizeEventSignal(const QSize&)), this, SLOT(resize_timer(const QSize&)));

    labels.push_back(new QLabel("Таймер"));
    labels.last()->setFont(QFont("Times New Roman", 14));
    labels.last()->setAlignment(Qt::AlignHCenter);
    labels.push_back(new QLabel("????"));
    labels.last()->setFont(QFont("Times New Roman", 14));
    labels.last()->setAlignment(Qt::AlignHCenter);

    timer->setInterval(5000);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
}

main_class::~main_class()
{
    delete main_view;
    delete main_scene;
    delete timer_view;
    delete timer_scene;
    delete sup_view;
    delete sup_scene;
    for(int i = 0; i < labels.size(); i++)
    {
        delete labels[i];
    }
    labels.clear();
    delete timer;
}

QList<my_gview *> main_class::get_views()
{
    QList<my_gview *> res;
    res.push_back(main_view);
    res.push_back(timer_view);
    res.push_back(sup_view);
    return res;
}

QList<QLabel *> main_class::get_labels()
{
    return labels;
}

void main_class::update()
{
    if (cur_iter != 0) timers_line[cur_iter - 1]->setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    if (cur_iter == 8) cur_iter = 0;
    timers_line[cur_iter]->setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    cur_iter++;
}

void main_class::resize_timer(const QSize& size)
{
    timer_scene->setSceneRect(0, 0, size.width(), size.height());
    QGraphicsLineItem* line;
    int i = 270;
    if (timers_line.size())
    {
        foreach(line, timers_line){
            line->setLine(size.width() / 2 + size.height() / 7 * qCos((i * M_PI) / 180),
                          size.height() / 2 + size.height() / 7 * qSin((i * M_PI) / 180),
                          size.width() / 2 + size.height() / 3.5 * qCos((i * M_PI) / 180),
                          size.height() / 2 + size.height() / 3.5 * qSin((i * M_PI) / 180));
            line->setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            i += 45;
        }
    }
    else
    {
        for (int i = 270; i < 630; i += 45)
        {
            timers_line.push_back(timer_scene->addLine(size.width() / 2 + size.height() / 7 * qCos((i * M_PI) / 180),
                                                       size.height() / 2 + size.height() / 7 * qSin((i * M_PI) / 180),
                                                       size.width() / 2 + size.height() / 3.5 * qCos((i * M_PI) / 180),
                                                       size.height() / 2 + size.height() / 3.5 * qSin((i * M_PI) / 180),
                                                       QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)));
            timers_line.last()->pen().setWidth(3);
        }
    }
    labels[0]->setText(QString::number(timer_scene->sceneRect().height()));
    labels[1]->setText(QString::number(size.height()));
    if (cur_iter == 8) cur_iter = 0;
    timers_line[cur_iter]->setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}
