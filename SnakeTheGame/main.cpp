#include "game.h"
#include <QApplication>
#include <windows.h>
#include <SnakeBody.h>
#include <SnakeHead.h>
#include <fruit.h>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <QDebug>

Game* game;
SnakeHead* head;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();

    while(!game->gameOver)
    {
    game->show();
    game->start();

    return a.exec();
    }
}
