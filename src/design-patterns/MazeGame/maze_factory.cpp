#include "maze_factory.hpp"

#include <iostream>

MazeFactory::MazeFactory() { std::cout << "Init MazeFactory()" << std::endl; }

std::unique_ptr<Maze> MazeFactory::MakeMaze() const {
  return std::make_unique<Maze>();
}

std::unique_ptr<Wall> MazeFactory::MakeWall() const {
  return std::make_unique<Wall>();
}

std::unique_ptr<Room> MazeFactory::MakeRoom(int n) const {
  return std::make_unique<Room>(n);
}

std::shared_ptr<Door> MazeFactory::MakeDoor(Room* r1, Room* r2) const {
  return std::make_shared<Door>(r1, r2);
}
