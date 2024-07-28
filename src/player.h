#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "board.h"

class Player {
 private:
 protected:
  Color color;

 public:
  Player(Color c) {};
  virtual ~Player() {};

  Color getColor();
  virtual Move getMove() = 0;
};

#endif