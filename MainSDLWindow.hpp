#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>

class MainSDLWindow
{
public:
  MainSDLWindow(void);
  ~MainSDLWindow(void);

  int Init(const char *Bernard, int width, int height);
  SDL_Renderer *GetRenderer(void);

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};
