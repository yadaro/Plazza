#include "open.hpp"

T::T() {}

QRectF T::boundingRect() const
{
    return QRectF();
}

void T::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}