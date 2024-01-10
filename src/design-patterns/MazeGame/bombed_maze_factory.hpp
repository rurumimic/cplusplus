#ifndef BOMBED_MAZE_FACTORY_H
#define BOMBED_MAZE_FACTORY_H

#include <memory>

#include "bombed_wall.hpp"
#include "maze_factory.hpp"
#include "room_with_a_bomb.hpp"

class BombedMazeFactory : public MazeFactory {
 public:
  BombedMazeFactory();
  ~BombedMazeFactory() = default;

  BombedMazeFactory(const BombedMazeFactory&) = delete;
  BombedMazeFactory(BombedMazeFactory&&) = delete;
  BombedMazeFactory& operator=(const BombedMazeFactory&) = delete;
  BombedMazeFactory& operator=(BombedMazeFactory&&) = delete;

  [[nodiscard]] std::unique_ptr<Wall> MakeWall() const override {
    return std::make_unique<BombedWall>();
  }

  [[nodiscard]] std::unique_ptr<Room> MakeRoom(int n) const override {
    return std::make_unique<RoomWithABomb>(n);
  }
};

#endif  // BOMBED_MAZE_FACTORY_H
