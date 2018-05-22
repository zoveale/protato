#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Global.h"

#include "Inputs.h"
#include "Graphics.h"
#include "Tile.h"
#include "GameObjects.h"
#include "PlayerOne.h"
//#include levels

//#include ??

class System {

  private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event keypresses;
  SDL_Rect camera;
  SDL_Rect tileBounds;
  SDL_Texture* loaded;

 
  Inputs input;
  Graphics levels[5];
  Tile tiles[5];
  PlayerOne player;

  public:
  System();
  
  void InitSystems();
  void Gameloop();
  
  //SDL systems
  SDL_Texture* Load(std::string texture);

  void InitSDL();
  void InitSDL_IMG();
  ~System();
};


#endif // !SYSTEM_H
