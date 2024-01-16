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
  virtual ~MazeFactory() = default;

  MazeFactory(const MazeFactory&) = delete;             // copy constructor
  MazeFactory(MazeFactory&&) = delete;                  // move constructor
  MazeFactory& operator=(const MazeFactory&) = delete;  // copy assignment
  MazeFactory& operator=(MazeFactory&&) = delete;       // move assignment

  [[nodiscard]] virtual std::unique_ptr<Maze> MakeMaze() const = 0;
  [[nodiscard]] virtual std::unique_ptr<Wall> MakeWall() const = 0;
  [[nodiscard]] virtual std::unique_ptr<Room> MakeRoom(int n) const = 0;
  virtual std::shared_ptr<Door> MakeDoor(Room* r1, Room* r2) const = 0;
};

#endif  // MAZE_FACTORY_H
