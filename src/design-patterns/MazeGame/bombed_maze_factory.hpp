#ifndef BOMBED_MAZE_FACTORY_H
#define BOMBED_MAZE_FACTORY_H

#include <memory>

#include "maze_factory.hpp"

class BombedMazeFactory : public MazeFactory {
 public:
  BombedMazeFactory();
  ~BombedMazeFactory() override = default;

  BombedMazeFactory(const BombedMazeFactory&) = delete;
  BombedMazeFactory(BombedMazeFactory&&) = delete;
  BombedMazeFactory& operator=(const BombedMazeFactory&) = delete;
  BombedMazeFactory& operator=(BombedMazeFactory&&) = delete;

  [[nodiscard]] std::unique_ptr<Maze> MakeMaze() const override;
  [[nodiscard]] std::unique_ptr<Wall> MakeWall() const override;
  [[nodiscard]] std::unique_ptr<Room> MakeRoom(int n) const override;
  std::shared_ptr<Door> MakeDoor(Room* r1, Room* r2) const override;
};

#endif  // BOMBED_MAZE_FACTORY_H
