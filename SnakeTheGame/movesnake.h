#ifndef MOVESNAKE_H
#define MOVESNAKE_H

#include <QMainWindow>
#include "SnakeBody.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
class movesnake: public QGraphicsRectItem
{
public:
    movesnake();
    void move(QKeyEvent* keyEvent);
};

#endif // MOVESNAKE_H
