#ifndef OPEN
# define OPEN

#include <QApplication>
#include <QWidget>
#include <QtWidgets>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>

class T : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    T();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif