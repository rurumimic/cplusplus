#ifndef BOMBED_MAZE_FACTORY_H
#define BOMBED_MAZE_FACTORY_H

#include <iostream>
#include <memory>

#include "BombedWall.h"
#include "MazeFactory.h"
#include "RoomWithABomb.h"

class BombedMazeFactory : public MazeFactory {
 public:
  BombedMazeFactory();
  ~BombedMazeFactory() = default;

  BombedMazeFactory(const BombedMazeFactory&) = delete;  // copy constructor
  BombedMazeFactory(BombedMazeFactory&&) = delete;       // move constructor
  BombedMazeFactory& operator=(const BombedMazeFactory&) =
      delete;  // copy assignment
  BombedMazeFactory& operator=(BombedMazeFactory&&) =
      delete;  // move assignment

  [[nodiscard]] std::unique_ptr<Wall> MakeWall() const override {
    return std::make_unique<BombedWall>();
  }

  [[nodiscard]] std::unique_ptr<Room> MakeRoom(int n) const override {
    return std::make_unique<RoomWithABomb>(n);
  }
};

#endif  // BOMBED_MAZE_FACTORY_H
