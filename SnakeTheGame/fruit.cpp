#include "fruit.h"
#include <QBrush>
#include <game.h>

Fruit::Fruit(QGraphicsItem *parent){
    // draw
    setRect(0,0,25,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
