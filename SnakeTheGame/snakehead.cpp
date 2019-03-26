#include "snakehead.h"
#include <QBrush>
#include "Fruit.h"
#include "SnakeBody.h"
#include "game.h"
#include <QDebug>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;
extern Game* game;

SnakeHead::SnakeHead(QGraphicsItem *parent){
    // draw
    setRect(0,0,25,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);

    // make focusable
    setFlag(QGraphicsItem::ItemIsFocusable,true);

    // TODO remove, test
    SnakeBody* b1 = new SnakeBody();
    b1->setPos(0,50);
    game->scene->addItem(b1);
    snakeBodies.prepend(b1);
}

void SnakeHead::keyPressEvent(QKeyEvent *keyEvent){
    // move up
    if (keyEvent->key() == Qt::Key_Up){
        game->dir = game->UP;
        prevPos = pos();
        int xPos = x();
        int yPos = y() - boundingRect().height();
        setPos(xPos,yPos);

        moveBodies();
    }

    // move down
    if (keyEvent->key() == Qt::Key_Down){
        game->dir = game->DOWN;
        prevPos = pos();
        int xPos = x();
        int yPos = y() + boundingRect().height();
        setPos(xPos,yPos);

        moveBodies();
    }

    // move right
    if (keyEvent->key() == Qt::Key_Right){
        game->dir = game->RIGHT;
        prevPos = pos();
        int xPos = x() + boundingRect().width();
        int yPos = y();
        setPos(xPos,yPos);

        moveBodies();
    }

    // move left
    if (keyEvent->key() == Qt::Key_Left){
        game->dir = game->LEFT;
        prevPos = pos();
        int xPos = x() - boundingRect().width();
        int yPos = y();
        setPos(xPos,yPos);
        moveBodies();
    }

    // elongate if collides with Fruit
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        if (typeid(*cItems[i]) == typeid(Fruit)){
            // fruit found in collision list
            game->score+=10;
            game->fruitX = rand() % game->width;
            game->fruitY = rand() % game->height;
            game->f1->setPos(game->fruitX,game->fruitY);
            elongate();
            qDebug() << "Score:" << game->score;
        }
    }

    //check for snake hitting bound edge
    if(x() > game->width-1 || x() < 0 || y() > game->height-1 || y() < 0)
    {
        game->gameOver = true;
        qDebug() << "You hit the edge gameOver is: " << game->gameOver << endl;
    }

    for (size_t i = 0, n = cItems.size(); i < n; ++i)
    {
        if (typeid(*cItems[i]) == typeid(SnakeBody))
        {
            qDebug() << "You hit yourself. gameOver is: " << game->gameOver << endl;
            game->gameOver = true;
        }
    }

    //check for gameOver
    if(game->gameOver == true)
    {
        exit(0);
    }



}

void SnakeHead::move(QKeyEvent *Event)
{
    //continue moving after keypress
    switch (game->dir)
    {
        case game->LEFT:
        {
            while(!Event)
            {
            prevPos = pos();
            int xPos = x() - boundingRect().width();
            int yPos = y();
            setPos(xPos,yPos);
            moveBodies();
            }
            break;
        }
        case game->RIGHT:
        {
            while(!Event)
            {
            game->dir = game->RIGHT;
            prevPos = pos();
            int xPos = x() + boundingRect().width();
            int yPos = y();
            setPos(xPos,yPos);
            moveBodies();
            }
            break;
        }
        case game->UP:
        {
            while(!Event)
            {
            prevPos = pos();
            int xPos = x();
            int yPos = y() - boundingRect().height();
            setPos(xPos,yPos);
            moveBodies();
            }
            break;
        }
        case game->DOWN:
        {
            while(!Event)
            {
            prevPos = pos();
            int xPos = x();
            int yPos = y() + boundingRect().height();
            setPos(xPos,yPos);
            moveBodies();
            }
            break;
        }
        default:
            break;
    }
}

void SnakeHead::elongate(){
    // add new SnakeBody to list
    SnakeBody* body = new SnakeBody();
    snakeBodies.prepend(body);

    // properly position the body
    body->setPos(-200,-200); // TODO
    game->scene->addItem(body);
}

void SnakeHead::moveBodies(){
    // traverses through list of bodies and moves them properly

    // move all bodies from back to front
    for (size_t i = 0, n = snakeBodies.size()-1; i < n; ++i){
        snakeBodies[i]->setPos(snakeBodies[i+1]->pos());

    }

    // move front body to previous position of head
    snakeBodies.last()->setPos(prevPos);
}
