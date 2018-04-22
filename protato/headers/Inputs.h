#ifndef INPUTS_H
#define INPUTS_H
#include <SDL.h>

class Inputs {
  private:
  SDL_Event e;
  bool quit;

  public:
  Inputs();
  void SetEventHandler(SDL_Event e);
  bool Quit();
  void Process();

  ~Inputs();
};

#endif // !SYSTEM_H