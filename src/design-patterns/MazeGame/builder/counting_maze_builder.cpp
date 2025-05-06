#include "counting_maze_builder.hpp"

#include <iostream>

CountingMazeBuilder::CountingMazeBuilder() : roomsCount(0), doorsCount(0) {
  std::cout << "Init CountingMazeBuilder()" << std::endl;
}

void CountingMazeBuilder::BuildMaze() {
  std::cout << "CountingMazeBuilder::BuildMaze()" << std::endl;
}

void CountingMazeBuilder::BuildRoom(const int room) {
  std::cout << "CountingMazeBuilder::BuildRoom(" << room << ")" << std::endl;
  roomsCount++;
}

void CountingMazeBuilder::BuilderDoor(const int roomFrom, const int roomTo) {
  std::cout << "CountingMazeBuilder::BuilderDoor(" << roomFrom << ", " << roomTo
            << ")" << std::endl;
  doorsCount++;
}

std::unique_ptr<Maze> CountingMazeBuilder::GetMaze() { return nullptr; }

void CountingMazeBuilder::GetCounts(int& rooms, int& doors) const {
  rooms = roomsCount;
  doors = doorsCount;
}

void CountingMazeBuilder::AddWall(int room, Direction direction) {}
