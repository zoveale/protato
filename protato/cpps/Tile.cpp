#include "..\headers\Tile.h"



Tile::Tile() {
  tilePos.empty();
  tileIdentity = -1;
  tiles.empty();
}


Tile::~Tile() {}

void Tile::SetRenderer(SDL_Renderer * r) {
this->renderer = r;
}

void Tile::SetTilePos(int i, int x, int y) {
  //tilePos->at(i).x = x;
}

void Tile::AddTileTexture(SDL_Texture* tile) {
  tiles.push_back(tile);
}




void Tile::setTile(std::string levelTileInfo) {

  std::ifstream map(levelTileInfo);
  SDL_Rect temp{0, 0, TILE_SIZE, TILE_SIZE};
  std::cout << tileIdentity << "\n";
  for (int i = 0; i < TOTAL_TILES; i++) {


    map >> tileIdentity;
    tileType.push_back(tileIdentity);

    temp.x = xpos;
    temp.y = ypos;
    tilePos.push_back(temp);

    std::cout << tileType.at(i) << " ";
    xpos += TILE_SIZE;
    if (xpos >= LEVEL_WIDTH) {
      ypos += TILE_SIZE;
      xpos = 0;
      std::cout << "\n";
    }

  }
  std::cout << tilePos.size() << "\n";
}

void Tile::DrawTiles(SDL_Rect &cam) {

  for (int i = 0; i < TOTAL_TILES; i++) {
    //std::cout << tilePos.at(i).x << " " << tilePos.at(i).y << "\n";
    SDL_RenderCopy(renderer, tiles.at(tileType.at(i)), &cam, &tilePos.at(i));
  }
 
}
