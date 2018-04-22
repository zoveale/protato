#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Inputs.h"

class System {

  private:
  SDL_Window *window;
  const SDL_Renderer *renderer;
  SDL_Event keypresses;

  static const int SCREEN_WIDTH = 640;
  static const int SCREEN_HEIGHT = 480;

  Inputs input;

  public:
  System();
  void InitSys();
  void Gameloop();

  ~System();
};

#endif // !SYSTEM_H
