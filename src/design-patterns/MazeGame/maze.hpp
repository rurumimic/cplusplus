#ifndef MAZE_H
#define MAZE_H

#include <memory>
#include <vector>

#include "room.hpp"

class Maze {
 public:
  Maze();
  ~Maze() = default;

  Maze(const Maze&) = delete;             // copy constructor
  Maze(Maze&&) = delete;                  // move constructor
  Maze& operator=(const Maze&) = delete;  // copy assignment
  Maze& operator=(Maze&&) = delete;       // move assignment

  void AddRoom(std::unique_ptr<Room> room);
  [[nodiscard]] Room* GetRoom(const int) const;

 private:
  std::vector<std::unique_ptr<Room>> rooms;
};

#endif  // MAZE_H
