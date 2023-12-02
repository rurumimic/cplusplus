#include <iostream>

#include "EnchantedMazeFactory.h"
#include "MazeGame.h"
#include "config.h"

int abstract_factory() {
  std::cout << "EnchantedMazeGame" << std::endl;

  MazeGame mazeGame;
  EnchantedMazeFactory factoryEnchanted;

  Maze* maze = mazeGame.CreateMaze(factoryEnchanted);
  Room* r1 = maze->RoomNo(1);

  std::cout << "Room 1: " << r1->GetRoomNumber() << std::endl;

  return 0;
}

int main(int argc, char* argv[]) {
  std::cout << "MazeGame" << std::endl;

  MazeGame mazeGame;
  Maze* maze = mazeGame.CreateMaze();
  Room* r1 = maze->RoomNo(1);

  std::cout << "Room 1: " << r1->GetRoomNumber() << std::endl;

  abstract_factory();

  return 0;
}

