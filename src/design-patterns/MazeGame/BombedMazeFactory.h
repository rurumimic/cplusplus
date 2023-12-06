#ifndef BOMBED_MAZE_FACTORY_H
#define BOMBED_MAZE_FACTORY_H

#include "BombedWall.h"
#include "MazeFactory.h"
#include "RoomWithABomb.h"

class Room;
class Wall;
class MazeFactory;

class BombedMazeFactory : public MazeFactory {
 public:
  BombedMazeFactory();

  Wall* MakeWall() const override {
    return new BombedWall;
  }

  Room* MakeRoom(int n) const override {
    return new RoomWithABomb(n);
  }

};

#endif  // BOMBED_MAZE_FACTORY_H
