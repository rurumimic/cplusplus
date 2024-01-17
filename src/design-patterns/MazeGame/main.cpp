#include <iostream>

#include "config.h"
#include "maze_game.hpp"

void version() {
  std::cout << "v" << PATTERNS_VERSION_MAJOR << "." << PATTERNS_VERSION_MINOR
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
