#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"

void keyboard() {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP]) {
     
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
   
  }
}

int main()
{

    {
        MainSDLWindow win;
        win.Init("snake", 800, 600);

        SDL_Rect rectangle;
        rectangle.x = 8;
        rectangle.y = 16;
        rectangle.w = 32;
        rectangle.h = 32;

        SDL_SetRenderDrawColor(win.GetRenderer(), 255, 0, 0, 255);
        SDL_RenderFillRect(win.GetRenderer(), &rectangle);
        SDL_RenderPresent(win.GetRenderer());

        SDL_Delay(5000);
    }
}