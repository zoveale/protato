#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>
//#include <string>

class Graphics {
  private:
  SDL_Texture* loaded;
  SDL_Renderer* renderer;
  SDL_Rect camVeiw;

  SDL_Texture* currentState;
  std::vector<SDL_Texture*> state;
  std::vector<SDL_Texture*> tiles;

  const int TILE_SIZE = 32;
  const int TOTAL_TILES = 800;

  public:
  Graphics();
  void SetRenderer(SDL_Renderer* r);

  SDL_Texture* Load(std::string texture);
  
  void SetState(SDL_Texture* state);

  void AddState(SDL_Texture* state);
  SDL_Texture* GetState() const; 
  //test draw
  void Draw(SDL_Rect& cam);
  void DrawTiles(SDL_Rect& cam, const int lw, const int lh);
  ~Graphics();
};

#endif // !GRAPHICS_H