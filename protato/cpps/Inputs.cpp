#include "..\headers\Inputs.h"



Inputs::Inputs() {
  quit = false;
}

void Inputs::SetEventHandler(SDL_Event e) {
 this->e = e;
}

bool Inputs::Quit() {
  return this->quit;
}


void Inputs::Process() {
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      quit = true;
      printf( "x-out quit\n");
    }
    if (e.type == SDL_KEYDOWN &&
      e.key.keysym.sym == SDLK_w) {
      KEY.W = true;
      //std::cout<< "up";
    }
    if (e.type == SDL_KEYUP &&
      e.key.keysym.sym == SDLK_w) {
      KEY.W = false;
      //std::cout << "-x ";
    }
    if (e.type == SDL_KEYDOWN &&
      e.key.keysym.sym == SDLK_s) {
      KEY.S = true;
      //std::cout << " down";
    }
    if (e.type == SDL_KEYUP &&
      e.key.keysym.sym == SDLK_s) {
      KEY.S = false;
      //std::cout << "-x ";
    }
    if (e.type == SDL_KEYDOWN &&
      e.key.keysym.sym == SDLK_a) {
      KEY.A = true;
      //std::cout << " left";
    }
    if (e.type == SDL_KEYUP &&
      e.key.keysym.sym == SDLK_a) {
      KEY.A = false;
      //std::cout << "-x ";
    }

    if (e.type == SDL_KEYDOWN &&
      e.key.keysym.sym == SDLK_d) {
      KEY.D = true;
      //std::cout << " right";
    }
    if (e.type == SDL_KEYUP &&
      e.key.keysym.sym == SDLK_d) {
      KEY.D = false;
      //std::cout << "-x ";
    }
  }

}

KEY_STATE Inputs::GetInput() {
  return this->KEY;
}

Inputs::~Inputs() {}
