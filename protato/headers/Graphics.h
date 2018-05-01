#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>
#include <fstream>
#include "Global.h"
//#include <string>

class Graphics {
  private:
  SDL_Renderer* renderer;
  SDL_Rect camVeiw;
  
  SDL_Texture* currentState;


  std::vector<SDL_Texture*> state;
  std::vector<SDL_Texture*> tileSheet;
  
  public:

  Graphics();
  void SetRenderer(SDL_Renderer* r);

  void SetState(SDL_Texture* state);

  void AddTile(SDL_Texture* tile);
  void AddState(SDL_Texture* state);

  SDL_Texture* GetState() const;
  //test draw
  void Draw(SDL_Rect& cam);

  //void DrawTiles(SDL_Rect& cam);
  //void setTile(std::string levelTileInfo, Tiles* test[]);

  ~Graphics();
};


#endif // !GRAPHICS_H