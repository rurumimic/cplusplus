#include "maze_factory.hpp"

#include <iostream>

MazeFactory::MazeFactory() { std::cout << "Init MazeFactory()" << std::endl; }

std::unique_ptr<Maze> MazeFactory::MakeMaze() const {
  std::cout << "MazeFactory::MakeMaze()" << std::endl;
  return std::make_unique<Maze>();
}

std::unique_ptr<Wall> MazeFactory::MakeWall() const {
  std::cout << "MazeFactory::MakeWall()" << std::endl;
  return std::make_unique<Wall>();
}

std::unique_ptr<Room> MazeFactory::MakeRoom(int n) const {
  std::cout << "MazeFactory::MakeRoom(" << n << ")" << std::endl;
  return std::make_unique<Room>(n);
}

std::shared_ptr<Door> MazeFactory::MakeDoor(Room* r1, Room* r2) const {
  std::cout << "MazeFactory::MakeDoor(" << r1->GetRoomNumber() << ", " << r2->GetRoomNumber()
            << ")" << std::endl;
  return std::make_shared<Door>(r1, r2);
}
