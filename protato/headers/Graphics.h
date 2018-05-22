#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>
#include "Global.h"
//#include <string>

class Graphics {
  private:
  SDL_Renderer* renderer;

  SDL_Rect levelRect;
  SDL_Point pos;
  
  SDL_Texture* currentState;
  std::vector<SDL_Texture*> state;
  
  
  
  public:

  Graphics();
  void SetRenderer(SDL_Renderer* r);

  SDL_Rect LevelRect();
  void SetState(SDL_Texture* state);
  void SetPlayerPos(int x, int y);
  SDL_Point StartPos();
  
  void AddState(SDL_Texture* state);

  SDL_Texture* GetState() const;
  //test draw
  void SetCamera(SDL_Rect& cam);
  void SetTileBounds(SDL_Rect& tileBounds);
  void Draw(SDL_Rect& cam);

  
  ~Graphics();
};


#endif // !GRAPHICS_H