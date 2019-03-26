#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include <QMainWindow>
#include <QGraphicsRectItem>

class SnakeBody: public QGraphicsRectItem{
public:
    SnakeBody(QGraphicsItem* parent=NULL);
};

#endif // SNAKEBODY_H
