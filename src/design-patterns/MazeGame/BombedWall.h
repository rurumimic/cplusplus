#ifndef BOMBED_WALL_H
#define BOMBED_WALL_H

#include "Wall.h"

class BombedWall : public Wall {
 public:
  BombedWall();
  ~BombedWall() = default;

  BombedWall(const BombedWall&) = delete;             // copy constructor
  BombedWall(BombedWall&&) = delete;                  // move constructor
  BombedWall& operator=(const BombedWall&) = delete;  // copy assignment
  BombedWall& operator=(BombedWall&&) = delete;       // move assignment
};

#endif  // BOMBED_WALL_H
