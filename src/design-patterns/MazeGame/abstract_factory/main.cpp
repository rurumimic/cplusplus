#include <iostream>

#include "MazeGame.h"
#include "EnchantedMazeFactory.h"
#include "config.h"

int main(int argc, char* argv[]) {
  std::cout << "EnchantedMazeGame" << std::endl;

  MazeGame mazeGame;
  EnchantedMazeFactory factoryEnchanted;

  Maze* maze = mazeGame.CreateMaze(factoryEnchanted);
  Room* r1 = maze->RoomNo(1);

  std::cout << "Room 1: " << r1->GetRoomNumber() << std::endl;

  return 0;
}
