#ifndef PLAYERONE_H
#define PLAYERONE_H

#include "GameObjects.h"
class PlayerOne:
  public GameObjects {
  private:
  //GameObjects player;
  public:
 

  PlayerOne();

  void Update(SDL_Rect& camera);
  ~PlayerOne();
};


#endif // !PLAYERONE_H
