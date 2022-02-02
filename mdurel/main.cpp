#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"


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