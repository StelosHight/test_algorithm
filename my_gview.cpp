#include "my_gview.h"

my_gview::my_gview(QGraphicsView *parent): QGraphicsView(parent)
{

}

void my_gview::resizeEvent(QResizeEvent *event)
{
    emit ResizeEventSignal(event->size());
    QGraphicsView::resizeEvent(event);
}
