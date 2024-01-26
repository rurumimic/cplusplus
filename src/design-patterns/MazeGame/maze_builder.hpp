#ifndef MAZE_BUILDER_H
#define MAZE_BUILDER_H

#include <memory>

#include "maze.hpp"

class MazeBuilder {
 public:
  ~MazeBuilder() = default;

  virtual void BuildMaze() = 0;
  virtual void BuildRoom(const int room) = 0;
  virtual void BuilderDoor(const int roomFrom, const int roomTo) = 0;

  [[nodiscard]] virtual std::unique_ptr<Maze> GetMaze() = 0;

 protected:
  MazeBuilder() = default;
};

#endif
