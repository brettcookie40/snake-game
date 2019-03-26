#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "fruit.h"

class Game: public QGraphicsView{
public:
    // constructors
    Game(QWidget* parent=NULL);

    //public variables
    const int width = 800;
    const int height = 600;
    int xval = width/2;
    int yval = height/2;
    bool gameOver = false;
    int fruitX = rand() % width;
    int fruitY = rand() % height;
    int score = 0;
    enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
    Fruit* f1 = new Fruit();
    Fruit* f2 = new Fruit();
    // public methods
    void start();

    // public attributes
    QGraphicsScene* scene;

private:
    };


#endif // GAME_H
