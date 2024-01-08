#include "MazeFactory.h"

MazeFactory::MazeFactory() { std::cout << "Init MazeFactory()" << std::endl; }

std::unique_ptr<Maze> MazeFactory::MakeMaze() const {
  std::cout << "MakeMaze()" << std::endl;
  return std::make_unique<Maze>();
}

std::unique_ptr<Wall> MazeFactory::MakeWall() const {
  std::cout << "MakeWall()" << std::endl;
  return std::make_unique<Wall>();
}

std::unique_ptr<Room> MazeFactory::MakeRoom(int n) const {
  std::cout << "MakeRoom(" << n << ")" << std::endl;
  return std::make_unique<Room>(n);
}

std::shared_ptr<Door> MazeFactory::MakeDoor(Room* r1, Room* r2) {
  std::cout << "MakeDoor(" << r1->GetRoomNumber() << ", " << r2->GetRoomNumber()
            << ")" << std::endl;
  return std::make_shared<Door>(r1, r2);
}
