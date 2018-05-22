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
  //void SetTilePos(int i, int x, int y);
  void AddTileTexture(SDL_Texture* tile);
  void DrawTiles(SDL_Rect &cam, SDL_Rect& level);
  //SDL_Rect tilePosition(int x, int y);
  private:
  SDL_Renderer* renderer;

  //std::vector<SDL_Rect> tilePos;
  int tileAnchor[40][30];
  SDL_Rect tileRec[40][30];
  
  
  int tileIdentity;
  int tileType[40][30];

  int xpos;
  int ypos;

  std::vector<SDL_Texture*> tileTexture;

};


#endif // !TILE_H