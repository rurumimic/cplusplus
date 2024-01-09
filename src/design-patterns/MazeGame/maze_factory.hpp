#ifndef MAZE_FACTORY_H
#define MAZE_FACTORY_H

#include <memory>

#include "door.hpp"
#include "maze.hpp"
#include "room.hpp"
#include "wall.hpp"

class MazeFactory {
 public:
  MazeFactory();

  [[nodiscard]] virtual std::unique_ptr<Maze> MakeMaze() const;
  [[nodiscard]] virtual std::unique_ptr<Wall> MakeWall() const;
  [[nodiscard]] virtual std::unique_ptr<Room> MakeRoom(int n) const;
  virtual std::shared_ptr<Door> MakeDoor(Room* r1, Room* r2) const;
};

#endif  // MAZE_FACTORY_H
