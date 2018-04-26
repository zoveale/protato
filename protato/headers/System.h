#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Inputs.h"
#include "Graphics.h"
//#include levels
//#include gameobjects
//#include ??

class System {

  private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event keypresses;
  SDL_Rect camera;

  static const int LEVEL_WIDTH = 1280;
  static const int LEVEL_HEIGHT = 960;
  
  static const int SCREEN_WIDTH = 640;
  static const int SCREEN_HEIGHT = 480;
  

  Inputs input;
  Graphics levels[5];

  public:
  System();
  
  void InitSystems();
  void Gameloop();

  //SDL systems
  void InitSDL();
  void InitSDL_IMG();
  ~System();
};

#endif // !SYSTEM_H
