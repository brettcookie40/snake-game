#ifndef FRUIT_H
#define FRUIT_H

#include <QMainWindow>
#include <QGraphicsEllipseItem>

class Fruit: public QGraphicsEllipseItem{
public:
    Fruit(QGraphicsItem* parent=NULL);
};

#endif // FRUIT_H
