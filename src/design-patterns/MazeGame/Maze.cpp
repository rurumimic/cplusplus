#include "Maze.h"

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <vector>

void Maze::AddRoom(std::unique_ptr<Room> room) {
  rooms.push_back(std::move(room));
}

Room* Maze::GetRoom(int n) const {
  for (const std::unique_ptr<Room>& room : rooms) {
    if (room->GetRoomNumber() == n) {
      return room.get();
    }
  }

  return nullptr;
}
