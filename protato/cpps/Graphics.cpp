#include "..\headers\Graphics.h"



Graphics::Graphics() {
  renderer = nullptr;
  currentState = nullptr;

  //FIX ME NEED GOLBAL SCREEN HEIGHT/WIDTH
  camVeiw.w = LEVEL_WIDTH;
  camVeiw.h = LEVEL_HEIGHT;
}

void Graphics::SetRenderer(SDL_Renderer * r) {
  this->renderer = r;
}



void Graphics::SetState(SDL_Texture * state) {
  this->currentState = state;
}

void Graphics::AddTile(SDL_Texture * tile) {
  this->tileSheet.push_back(tile);
  
}

void Graphics::AddState(SDL_Texture * state) {
  this->state.push_back(state);
}

SDL_Texture * Graphics::GetState() const {
  return currentState;
}


void Graphics::Draw(SDL_Rect& cam) {
  //STATE.AT(0) IS LEVEL BACKGROUND
  SDL_RenderCopy(renderer, state.at(0), &cam, NULL);
  
  

}



Graphics::~Graphics() {}
