#include "../headers/System.h"


int main(int argc, char* args[]) {

  System gameSystem;

  gameSystem.InitSys();
  gameSystem.Gameloop();

  return 0;
}