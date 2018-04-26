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
  }

}

Inputs::~Inputs() {}
