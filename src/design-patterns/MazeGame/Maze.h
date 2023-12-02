#ifndef MAZE_H
#define MAZE_H

#include <vector>

#include "Room.h"

class Maze {
 public:
  Maze() = default;

  void AddRoom(Room *);
  Room *RoomNo(int) const;

 private:
  std::vector<Room *> rooms;
};

#endif  // MAZE_H
