#ifndef MAINSDLWINDOW_HPP
#define MAINSDLWINDOW_HPP

#include <SDL2/SDL.h>
#include <stdio.h>

class MainSDLWindow
{
public:
  MainSDLWindow(void);
  ~MainSDLWindow(void);

  int Init(const char *Jesus, int width, int height);
  SDL_Renderer *GetRenderer(void);

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};
#endif