#include "..\headers\GameObjects.h"



GameObjects::GameObjects() {
  Xvelocity = 0;
  Yvelocity = 0;
  space = {0, 0, 0, 0};
  animation.empty();

}

void GameObjects::Init(SDL_Point pos, int w, int h) {
  this->space.x = pos.x;
  this->space.y = pos.y;
  this->space.w = w;
  this->space.h = h;
  position = pos;
}

void GameObjects::SetPos(SDL_Point pos) {
  this->space.x = pos.x;
  this->space.y = pos.y;
}

SDL_Point GameObjects::GetPos() {
  return position;
}



void GameObjects::setRenderer(SDL_Renderer * r) {
  this->renderer = r;
}

void GameObjects::AddTexture(SDL_Texture * t) {
  animation.push_back(t);
}

void GameObjects::Movement(KEY_STATE KEY) {
  if (KEY.W) {
    Yvelocity = -5;
    //std::cout << "\nPlayer True\n";
  }
  else if (KEY.S) {
    Yvelocity = 5;
  }
  else if (KEY.A) {
    Xvelocity = -5;
  }
  else if (KEY.D) {
    Xvelocity = 5;
  }
  else {
    Xvelocity = 0;
    Yvelocity = 0;
  }
  
}

SDL_Rect GameObjects::GetSpace() {
  return space;
}

 void GameObjects::Update(SDL_Rect& camera) {
  
  

  //std::cout << space.x << " " << space.y << "\n";
}

void GameObjects::Draw(SDL_Rect& cam) {
 
  //cam.x = (cam.x + space.w/2) - SCREEN_WIDTH /2 ;
  //cam.y = (cam.y + space.h/2) - SCREEN_HEIGHT / 2;
  SDL_Rect renderPosition{
    space.x - cam.x,
    space.y - cam.y,
    space.w, space.h
  };
  
  
  SDL_RenderCopy(renderer, animation.at(0), NULL, &renderPosition);
}




GameObjects::~GameObjects() {}
