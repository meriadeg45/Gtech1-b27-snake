#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"

SDL_Renderer *MainSDLWindow::GetRenderer(void)
{
    return this->renderer;
}

MainSDLWindow::MainSDLWindow()
{
    this->window = NULL;
    this->renderer = NULL;
}

MainSDLWindow::~MainSDLWindow()
{
    if (this->renderer != NULL)
        SDL_DestroyRenderer(this->renderer);
    if (this->window != NULL)
        SDL_DestroyWindow(this->window);
    SDL_Quit();
}

int MainSDLWindow::Init(const char *Jesus, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    this->window = SDL_CreateWindow(Jesus, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (this->window == NULL)
    {
        printf("Erreur de création de la fenêtre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
    if (this->renderer == NULL)
    {
        printf("Erreur de création du renderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    return 0;
}

int main()
{
    MainSDLWindow win;
    win.Init("Snake", 800, 600);

   

    SDL_Rect rectangle;

    rectangle.x = 8;
    rectangle.y = 14;
    rectangle.w = 32;
    rectangle.h = 32;

    SDL_SetRenderDrawColor(win.GetRenderer(), 255, 0, 0, 255);
    SDL_RenderFillRect(win.GetRenderer(), &rectangle);
    SDL_RenderPresent(win.GetRenderer());

    SDL_Delay(5000);

}