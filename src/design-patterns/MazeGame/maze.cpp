#include "maze.hpp"

#include <iostream>

Maze::Maze() { std::cout << "Init Maze()" << std::endl; }

void Maze::AddRoom(std::unique_ptr<Room> room) {
  int number = room->GetRoomNumber();
  rooms.push_back(std::move(room));

  std::cout << "Maze::AddRoom(" << number << ")" << std::endl;
}

Room* Maze::GetRoom(const int n) const {
  for (const auto& room : rooms) {
    if (room->GetRoomNumber() == n) {
      std::cout << "Maze::GetRoom(" << n << ")" << std::endl;
      return room.get();
    }
  }

  std::cout << "Can't find room " << n << " in maze" << std::endl;
  return nullptr;
}
