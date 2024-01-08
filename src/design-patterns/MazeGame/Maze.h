#ifndef MAZE_H
#define MAZE_H

#include <algorithm>
#include <memory>
#include <vector>

#include "Room.h"

class Maze {
 public:
  Maze() = default;
  ~Maze() = default;

  Maze(const Maze&) = delete;             // copy constructor
  Maze(Maze&&) = delete;                  // move constructor
  Maze& operator=(const Maze&) = delete;  // copy assignment
  Maze& operator=(Maze&&) = delete;       // move assignment

  void AddRoom(std::unique_ptr<Room> room);
  [[nodiscard]] Room* GetRoom(int) const;

 private:
  std::vector<std::unique_ptr<Room>> rooms;
};

#endif  // MAZE_H
