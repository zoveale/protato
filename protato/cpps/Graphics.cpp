#include "..\headers\Graphics.h"



Graphics::Graphics() {
  loaded = nullptr;
  renderer = nullptr;
  currentState = nullptr;

  //FIX ME NEED GOLBAL SCREEN HEIGHT/WIDTH
  camVeiw.w = 640;
  camVeiw.h = 480;
}

void Graphics::SetRenderer(SDL_Renderer * r) {
  this->renderer = r;
}

SDL_Texture* Graphics::Load(std::string texture) {
  SDL_Surface* loadedSurface = IMG_Load(texture.c_str());
  if (loadedSurface == nullptr) { printf("error loaded surface\n"); }
  else {
    this->loaded = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (this->loaded == nullptr) { printf("new texture error\n"); }
    SDL_FreeSurface(loadedSurface);
  }
  std::cout<< "level loaded\n";
  return this->loaded;
}

void Graphics::SetState(SDL_Texture * state) {
  this->currentState = state;
}

void Graphics::AddState(SDL_Texture * state) {
  this->state.push_back(state);
}

SDL_Texture * Graphics::GetState() const {
  return currentState;
}


void Graphics::Draw(SDL_Rect& cam) {
  
  SDL_RenderCopy(renderer, currentState, &cam, NULL);
}

void Graphics::DrawTiles(SDL_Rect & cam, const int lw, const int lh) {

  for (int i = 0; i < TOTAL_TILES; i++) {
      
  }

}

Graphics::~Graphics() {}
