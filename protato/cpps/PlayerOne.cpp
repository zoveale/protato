#include "..\headers\PlayerOne.h"




PlayerOne::PlayerOne() {}


void PlayerOne::Update(SDL_Rect & camera) {
  space.x += Xvelocity;
  space.y += Yvelocity;

  if (space.x < 0) {
    space.x = 0;
  }
  if (space.y < 0) {
    space.y = 0;
  }
  if (space.x > LEVEL_WIDTH - space.w) {
    space.x = LEVEL_WIDTH - space.w;
  }
  if (space.y > LEVEL_HEIGHT - space.h) {
    space.y = LEVEL_HEIGHT - space.h;
  }

  camera.x = space.x - camera.w / 2;
  camera.y = space.y - camera.h / 2;
  
}

PlayerOne::~PlayerOne() {}
