#include "Maze.h"

#include <vector>

void Maze::AddRoom(Room* room) { rooms.push_back(room); }

Room* Maze::RoomNo(int n) const {
  for (Room* room : rooms) {
    // TODO: find the room
  }

  return nullptr;
}
