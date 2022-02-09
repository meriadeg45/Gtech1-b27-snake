#pragma once


#include <SDL2/SDL.h>

#define FRUIT_SIZE_X 28
#define FRUIT_SIZE_Y 28
#define FRUIT_BORDER 4

class Fruit
{
public:
    Fruit();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setRandomCoord();
    void printFruit(SDL_Renderer *renderer);
    void debugPrint();
private:
    int x;
    int y;
};