#include <SDL2/SDL.h>
#include <iostream>
#include "MainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"
#include "constants.h"



int dir = DOWN;

int keyboard()
{
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP] && dir != DOWN)
  {
    dir = UP;
  }
  if (keystates[SDL_SCANCODE_DOWN] && dir != UP)
  {
    dir = DOWN;
  }
  if (keystates[SDL_SCANCODE_LEFT] && dir != RIGHT)
  {
    dir = LEFT;
  }
  if (keystates[SDL_SCANCODE_RIGHT] && dir != LEFT)
  {
    dir = RIGHT;
  }
  return 0;
}

int main()
{
  MainSDLWindow win;
  win.Init("snake", SCREEN_SIZE, SCREEN_SIZE);
  SDL_Rect rectangle;
  rectangle.w = 32;
  rectangle.h = 32;

  srand(time(NULL));
  Snake *snake = new Snake();

  do
  {
    keyboard();
    snake->Move(dir);
    snake->CheckFruit();

    SDL_SetRenderDrawColor(win.GetRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(win.GetRenderer());

    SDL_SetRenderDrawColor(win.GetRenderer(), 255, 0, 0, 255);
    Segment* s = snake->getHead();
    while ( s )
    {
      rectangle.x = s->GetX() * PIXELS;
      rectangle.y = s->GetY() * PIXELS;
      SDL_RenderFillRect(win.GetRenderer(), &rectangle);

      s = s->GetNext();
    }

    //dessiner fruit  
    
    rectangle.x = snake->GetFruit()->getX() * PIXELS;
    rectangle.y = snake->GetFruit()->getY() * PIXELS;
    SDL_SetRenderDrawColor(win.GetRenderer(), 0, 255, 0, 255);
    SDL_RenderFillRect(win.GetRenderer(), &rectangle);

    SDL_RenderPresent(win.GetRenderer());

    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        exit(0);
      }
    }

    SDL_Delay(50);
  } while (1);
}