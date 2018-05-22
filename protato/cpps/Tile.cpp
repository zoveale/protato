#include "..\headers\Tile.h"



Tile::Tile() {
  //tilePos.empty();
  tileIdentity = -1;
  tileTexture.empty();
  xpos = 0;
  ypos = 0;
}


Tile::~Tile() {}

void Tile::SetRenderer(SDL_Renderer * r) {
  this->renderer = r;
}

void Tile::AddTileTexture(SDL_Texture* tile) {
  tileTexture.push_back(tile);
}

void Tile::setTile(std::string levelTileInfo) {

  std::ifstream map(levelTileInfo);
  SDL_Rect temp{0, 0, TILE_SIZE, TILE_SIZE};
  //std::cout << tileIdentity << "\n";
  int tempInt = 0;
  for (int j = 0; j < 30; j++) {
    for (int i = 0; i < 40; i++) {


      map >> tileIdentity;

      temp.x = xpos;
      temp.y = ypos;

      tileType[i][j] = tileIdentity;
      tileRec[i][j] = temp;

      //std::cout << tileType[i][j] << " ";
      xpos += TILE_SIZE;
      if (xpos >= LEVEL_WIDTH) {
        ypos += TILE_SIZE;
        xpos = 0;
        //std::cout << "\n";
      }
      tileAnchor[i][j] = tempInt;
      tempInt++;
    }
  }
}

void Tile::DrawTiles(SDL_Rect &cam, SDL_Rect& level) {
  //FIXME::TILEcam- have an if statement to switch 
  //between camera.x.y and tilecam.x.y
  int x = (cam.x) / 32;
  int y = (cam.y) / 32;
  int xend = x + 20;
  int yend = y + 15;
  
  if ((cam.x + cam.w) < level.w) {
    xend++;
  }
  if ((cam.y + cam.h) < level.h) {
    yend++;
  }

 
 
  for (int j = y; j < yend; j++) {
    for (int i = x; i < xend; i++) {
      //std::cout << tileAnchor[i][j] << " ";
      tileRec[i][j].x = i*TILE_SIZE - cam.x;
      tileRec[i][j].y = j* TILE_SIZE - cam.y;
      /* //FIX ME::WHICH ONE IS BETTER?
         tileRec[i][j] = 
        SDL_Rect{i*TILE_SIZE - cam.x,
                 j* TILE_SIZE - cam.y,
                 TILE_SIZE, TILE_SIZE};

      */
      SDL_RenderCopy(renderer,
        tileTexture.at(tileType[i][j]),
        NULL, &tileRec[i][j]);
      
      
    }
    
    //std::cout << "\n";
  }
  
}
/*
SDL_Rect Tile::tilePosition(int x, int y) {
  int index;
  index = tileAnchor[x][y];

  return tilePos.at(index);
}
*/