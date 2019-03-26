#include "snakebody.h"
#include <QBrush>
#include <game.h>

SnakeBody::SnakeBody(QGraphicsItem *parent){
    // draw
    setRect(0,0,25,25);
    QBrush snake;
    snake.setStyle(Qt::DiagCrossPattern);
    snake.setColor(Qt::darkGreen);
    setBrush(snake);
}
