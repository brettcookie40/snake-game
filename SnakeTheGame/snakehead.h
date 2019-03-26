#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QMainWindow>
#include "SnakeBody.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>

class SnakeHead: public QGraphicsRectItem{
public:
    // constructors
    SnakeHead(QGraphicsItem* parent=NULL);

    // events
    void keyPressEvent(QKeyEvent* keyEvent);
    void move(QKeyEvent* Event);
    // public method
    void elongate();
    void moveBodies();

    QPointF prevPos;
private:
    QList<SnakeBody*> snakeBodies;

};

#endif // SNAKEHEAD_H
