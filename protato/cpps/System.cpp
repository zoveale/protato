#include "..\headers\System.h"



System::System() {
  camera.w = SCREEN_WIDTH;
  camera.h = SCREEN_HEIGHT;
  InitSDL(); //SDL initilization
  InitSDL_IMG(); //SDL_IMG init, PNGs ok!
  //TTF
  //AUDIO
  //other stuff
}


void System::InitSystems() {
  std::cout << "initialize all systems\n";

  //Init other systems
  input.SetEventHandler(keypresses);

  levels[0].SetRenderer(renderer);
  levels[0].SetState(levels[0].Load("graphics/backdropTest.png"));

}

void System::Gameloop() {
  std::cout << "start gameloop\n";
  
  while (!input.Quit()) {
    input.Process();
    SDL_RenderClear(renderer);
    
    
    //drawbackDrop
    levels[0].Draw(camera);
    //draw background tiles
    //draw interactable tiles
    //draw player
    //draw foreground tiles

    SDL_RenderPresent(renderer);
  }
}

void System::InitSDL() {
  //create window and renderer
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << SDL_GetError();
  }
  std::cout << "create window\n";
  //FIX ME:: add fuctions for screen Height and width
  window = SDL_CreateWindow("protato",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    SCREEN_WIDTH, SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN);

  std::cout << "create renderer\n";
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
}

void System::InitSDL_IMG() {

  // load support for the JPG and PNG image formats
  int flags = IMG_INIT_PNG;
  int initted = IMG_Init(flags);
  if ((initted&flags) != flags) {
    printf("IMG_Init: Failed to init required jpg and png support!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
  }
}

System::~System() {
  
}
