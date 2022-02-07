#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"
#include "snake.hpp"
#include "constants.h"
int dir = DOWN;
int keyboard()
{
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP])
  {
    dir = UP;
  }
  if (keystates[SDL_SCANCODE_DOWN])
  {
    dir = DOWN;
  }
  if (keystates[SDL_SCANCODE_LEFT])
  {
    dir = LEFT;
  }
  if (keystates[SDL_SCANCODE_RIGHT])
  {
    dir = RIGHT;
  }
  return 0;
}

int main()
{
  MainSDLWindow win;
  win.Init("snake", 800, 600);
  SDL_Rect rectangle;
  rectangle.w = 32;
  rectangle.h = 32;

  Snake *snake = new Snake();

  do
  {
    keyboard();
    snake->Move(dir);
    /*switch (dir)
    {
    case UP:
      rectangle.y--;
      break;
    case DOWN:
      rectangle.y++;
      break;
    case LEFT:
      rectangle.x--;
      break;
    case RIGHT:
      rectangle.x++;
      break;
    }*/

    SDL_SetRenderDrawColor(win.GetRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(win.GetRenderer());

    SDL_SetRenderDrawColor(win.GetRenderer(), 255, 0, 0, 255);
    Segment* s = snake->getHead();
    while ( s )
    {
      SDL_Rect r = { s->GetX() * GRIDSIZE, s->GetY() * GRIDSIZE, GRIDSIZE, GRIDSIZE };
      SDL_RenderFillRect(win.GetRenderer(), &r);

      s = s->GetNext();
    }

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