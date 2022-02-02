#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"
#define IsGameRunning = 1


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
    if (this->window != NULL)
        SDL_DestroyWindow(this->window);

    if (this->renderer != NULL)
        SDL_DestroyRenderer(this->renderer);

    SDL_Quit();
}

int MainSDLWindow::Init(const char *Bernard, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erreur d'Initialisation de la vidéo %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    this->window = SDL_CreateWindow(Bernard, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
    if (this->window == NULL)
    {
        printf("Erreur de l'affichage de la fenêtre %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
    if (this->renderer == NULL)
    {
        printf("Erreur de l'affichage du rendu %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    else
    {
        printf("Pas d'erreurs");
        return EXIT_SUCCESS;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    return 0;
}

