#include <random>
#include <iostream>
#include "fruit.hpp"
#include "MainSDLWindow.hpp"
#define PIXELS 32
#define SQUARES 20
#define SCREEN_SIZE (PIXELS * SQUARES)

#define Fruit_SIZE_X 32
#define Fruit_SIZE_Y 32

Fruit::Fruit()
{
    setRandomCoord();
}

int Fruit::getX()
{
    return this->x;
}

int Fruit::getY()
{
    return this->y;
}

void Fruit::setX(int xPos)
{
    this->x = xPos;
}

void Fruit::setY(int yPos)
{
    this->y = yPos;
}

void Fruit::setRandomCoord()
{
    int randx = rand() % (SQUARES - 1) + 1;
    int randy = rand() % (SQUARES - 1) + 1;
    this->x = randx;
    this->y = randy;
    printf("Fruit: %d : %d\n", x, y);

}

void Fruit::printFruit(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    SDL_Rect Fruit;
    Fruit.h = Fruit_SIZE_Y;
    Fruit.w = Fruit_SIZE_X;
    Fruit.x = this->x;
    Fruit.y = this->y;

    SDL_RenderFillRect(renderer, &Fruit);
}

void Fruit::debugPrint()
{
    printf("X: %d\nY: %d\n", this->x, this->y);
}