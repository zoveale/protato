#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H
#include <SDL.h>
#include <vector>
#include "Global.h"
#include <iostream>

#include "Inputs.h"

class GameObjects {
  protected:
  int Xvelocity;
  int Yvelocity;

  SDL_Point position;
  SDL_Rect space;
  std::vector<SDL_Texture*> animation;
  SDL_Renderer* renderer;
  KEY_STATE KEY;

  public:
  GameObjects();
  void Init(SDL_Point pos, int w, int h);

  void SetPos(SDL_Point pos);
  SDL_Point GetPos();
 

  void setRenderer(SDL_Renderer* r);
  void AddTexture(SDL_Texture* t); 

  void Movement(KEY_STATE KEY);

  SDL_Rect GetSpace();
  //void Update(SDL_Rect& camera);
  void Draw(SDL_Rect& cam);
  virtual void Update(SDL_Rect& camera) = 0;
  

  //SDL_Point getVelocity();

  ~GameObjects();
};


#endif // !GAMEOBJECTS_H