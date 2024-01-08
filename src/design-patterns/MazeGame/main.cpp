#include <iostream>

#include "MazeGame.h"
#include "config.h"

void version() {
  std::cout << "v" << Patterns_VERSION_MAJOR << "." << Patterns_VERSION_MINOR
            << std::endl;
}

int main(int argc, char* argv[]) {
  version();

  std::cout << "MazeGame" << std::endl;
  MazeGame mazeGame;
  std::unique_ptr<Maze> maze = mazeGame.CreateMaze();

  Room* r1 = maze->GetRoom(1);
  std::cout << "Room " << r1->GetRoomNumber() << std::endl;

  return 0;
}
