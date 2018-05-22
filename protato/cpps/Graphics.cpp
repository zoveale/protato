#include "..\headers\Graphics.h"



Graphics::Graphics() {
  renderer = nullptr;
  currentState = nullptr;

  //FIX ME NEED GOLBAL SCREEN HEIGHT/WIDTH
  levelRect.x = 0;
  levelRect.y = 0;
  levelRect.h = LEVEL_HEIGHT;
  levelRect.w = LEVEL_WIDTH;
 
}

void Graphics::SetRenderer(SDL_Renderer * r) {
  this->renderer = r;
}



SDL_Rect Graphics::LevelRect() {
  return levelRect;
}

void Graphics::SetState(SDL_Texture * state) {
  this->currentState = state;
}

void Graphics::SetPlayerPos(int x, int y) {
  this->pos.x = x;
  this->pos.y = y;
}

SDL_Point Graphics::StartPos() {
  return pos;
}



void Graphics::AddState(SDL_Texture * state) {
  this->state.push_back(state);
}

SDL_Texture * Graphics::GetState() const {
  return currentState;
}


void Graphics::SetCamera(SDL_Rect & cam) {
 
  if (cam.x < 0) {
    cam.x = 0;
  }
  if (cam.y < 0) {
    cam.y = 0;
  }
  if (cam.x > LEVEL_WIDTH - cam.w) {
    cam.x = LEVEL_WIDTH - cam.w;
  }
  if (cam.y > LEVEL_HEIGHT - cam.h) {
    cam.y = LEVEL_HEIGHT - cam.h;
  }
}

void Graphics::SetTileBounds(SDL_Rect & tileBounds) {
  if (tileBounds.x < 0) {
    tileBounds.x = 0;
  }
  if (tileBounds.y < 0) {
    tileBounds.y = 0;
  }
  if (tileBounds.x > LEVEL_WIDTH - tileBounds.w) {
    tileBounds.x = LEVEL_WIDTH - tileBounds.w;
  }
  if (tileBounds.y > LEVEL_HEIGHT - tileBounds.h) {
    tileBounds.y = LEVEL_HEIGHT - tileBounds.h;
  }
}

void Graphics::Draw(SDL_Rect& cam) {
  //STATE.AT(0) IS LEVEL BACKGROUND
  //SDL_Rect level{0, 0, LEVEL_WIDTH, LEVEL_HEIGHT };

  SDL_RenderCopy(renderer, state.at(0), &cam, nullptr);
}



Graphics::~Graphics() {}
