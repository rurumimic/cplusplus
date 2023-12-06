#include <iostream>

#include "MazeGame.h"
#include "config.h"

int main(int argc, char* argv[]) {
  std::cout << "MazeGame" << std::endl;

  MazeGame mazeGame;
  Maze* maze = mazeGame.CreateMaze();
  Room* r1 = maze->RoomNo(1);

  std::cout << "Room 1: " << r1->GetRoomNumber() << std::endl;

  return 0;
}

