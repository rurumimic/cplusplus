#include <iostream>

#include "BombedMazeFactory.h"
#include "MazeGame.h"
#include "EnchantedMazeFactory.h"
#include "config.h"

void version() {
  std::cout << "v" << Patterns_VERSION_MAJOR << "." << Patterns_VERSION_MINOR
            << std::endl;
}

void enchantedMazeGame() {
  std::cout << "EnchantedMazeGame" << std::endl;
  MazeGame mazeGame;
  EnchantedMazeFactory factory;
  Maze* maze = mazeGame.CreateMaze(factory);

  Room* r1 = maze->RoomNo(1);
  std::cout << "Room " << r1->GetRoomNumber() << std::endl;
}

void bombedMazeGame() {
  std::cout << "BombedMazeGame" << std::endl;
  MazeGame mazeGame;
  BombedMazeFactory factory;
  Maze* maze = mazeGame.CreateMaze(factory);

  Room* r1 = maze->RoomNo(1);
  std::cout << "Room " << r1->GetRoomNumber() << std::endl;
}

int main(int argc, char* argv[]) {
  version();

  enchantedMazeGame();
  bombedMazeGame();

  return 0;
}
