#include "game.h"
#include "ui_game.h"
#include "SnakeHead.h"
#include "Fruit.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <QDebug>

Game::Game(QWidget *parent): QGraphicsView(parent){
    // set the scene
    scene = new QGraphicsScene(0,0,800,600);
    setScene(scene);
}

void Game::start(){
    // create snakeHead
    SnakeHead* snakeHead = new SnakeHead();
    scene->addItem(snakeHead);
    snakeHead->setFocus();

    // create a fruit
    f1->setPos(fruitX,fruitY);
    scene->addItem(f1);


}
