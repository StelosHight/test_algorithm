#ifndef MY_GVIEW_H
#define MY_GVIEW_H

#include <QGraphicsView>
#include <QResizeEvent>

class my_gview: public QGraphicsView
{
    Q_OBJECT
public:
    my_gview(QGraphicsView *parent = nullptr);

signals:
    void ResizeEventSignal(const QSize &size);

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // MY_GVIEW_H
