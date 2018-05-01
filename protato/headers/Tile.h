#ifndef TILE_H
#define TILE_H
#include <SDL.h>
#include "Global.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

class Tile {
  public:
  Tile();
  ~Tile();
  void SetRenderer(SDL_Renderer* r);
  void setTile(std::string levelTileInfo);
  void SetTilePos(int i, int x, int y);
  void AddTileTexture(SDL_Texture* tile);
  void DrawTiles(SDL_Rect &cam);

  private:
  SDL_Renderer* renderer;

  std::vector<SDL_Rect> tilePos;
  //SDL_Rect levelsize{0,0, LEVEL_HEIGHT, LEVEL_WIDTH};
  int tileIdentity;
  std::vector<int> tileType;
  int xpos;
  int ypos;

  std::vector<SDL_Texture*> tiles;

};


#endif // !TILE_H