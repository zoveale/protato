#ifndef INPUTS_H
#define INPUTS_H
#include <SDL.h>
#include <iostream>
#include "Global.h"

enum ObjectDirection {
  IDEL, UP, DOWN, LEFT, RIGHT, TOTAL
};
struct KEY_STATE {
  bool UP = false;
  bool DOWN = false;
  bool LEFT = false;
  bool RIGHT = false;

  bool W = false;
  bool S = false;
  bool A = false;
  bool D = false;
};
class Inputs {
  private:
  SDL_Event e;
  KEY_STATE KEY;
  bool quit;

  
  public:
  Inputs();
  void SetEventHandler(SDL_Event e);
  bool Quit();
  void Process();
  KEY_STATE GetInput();
  ~Inputs();
};

#endif // !SYSTEM_H