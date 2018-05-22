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
  levels[0].AddState(Load("graphics/backdropTest.png"));
  levels[0].SetPlayerPos(0, 0);

  tiles[0].SetRenderer(renderer);
  tiles[0].setTile("tiles/levelOne.txt");
  //FIX_ME add sprite sheets and load one png
  tiles[0].AddTileTexture(NULL);
  tiles[0].AddTileTexture(Load("graphics/backgroundClimbOne.png"));
  tiles[0].AddTileTexture(Load("graphics/backgroundOneTile.png"));
  tiles[0].AddTileTexture(Load("graphics/backgroundTwoTile.png"));
  tiles[0].AddTileTexture(Load("graphics/damageOne.png"));
  tiles[0].AddTileTexture(Load("graphics/foregroundOne.png"));
  tiles[0].AddTileTexture(Load("graphics/walkOne.png"));
  tiles[0].AddTileTexture(Load("graphics/bounceTwo.png"));
  
  player.setRenderer(renderer);
  player.Init(levels[0].StartPos(), 25, 50);
  player.AddTexture(Load("graphics/playerOne.png"));

}

void System::Gameloop() {
  std::cout << "start gameloop\n";
  
  while (!input.Quit()) {
    input.Process();
    
    player.Movement(input.GetInput());
    
    //collisions
    //MAKE COLLISONS CLASS

    //Update Objects
    player.Update(camera);
    
    SDL_RenderClear(renderer);
    //Draw all
    levels[0].SetCamera(camera);
    levels[0].Draw(camera);
    tiles[0].DrawTiles(camera, levels[0].LevelRect());
    player.Draw(camera);

   
    
    //draw interactable tiles
    //draw player
    //draw foreground tiles

    SDL_RenderPresent(renderer);
    SDL_Delay(001);
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

SDL_Texture* System::Load(std::string texture) {
  SDL_Surface* loadedSurface = IMG_Load(texture.c_str());
  
  if (loadedSurface == nullptr) { printf("error loaded surface\n"); }
  else {
    loaded = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (loaded == nullptr) { printf("new texture error\n"); }
    SDL_FreeSurface(loadedSurface);
  }
  //std::cout << "texure loaded\n";
  return loaded;
}

System::~System() {
  
}
