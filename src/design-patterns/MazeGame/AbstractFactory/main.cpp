#include <iostream>

#include "BombedMazeFactory.h"
#include "EnchantedMazeFactory.h"
#include "MazeGame.h"
#include "config.h"

void version() {
  std::cout << "v" << Patterns_VERSION_MAJOR << "." << Patterns_VERSION_MINOR
            << std::endl;
}

void enchantedMazeGame() {
  std::cout << "EnchantedMazeGame" << std::endl;
  MazeGame mazeGame;
  EnchantedMazeFactory factory;
  std::unique_ptr<Maze> maze = mazeGame.CreateMaze(factory);

  Room* r1 = maze->GetRoom(1);
  std::cout << "Room " << r1->GetRoomNumber() << std::endl;
}

void bombedMazeGame() {
  std::cout << "BombedMazeGame" << std::endl;
  MazeGame mazeGame;
  BombedMazeFactory factory;
  std::unique_ptr<Maze> maze = mazeGame.CreateMaze(factory);

  Room* r1 = maze->GetRoom(1);
  std::cout << "Room " << r1->GetRoomNumber() << std::endl;
}

int main(int argc, char* argv[]) {
  version();

  enchantedMazeGame();
  bombedMazeGame();

  return 0;
}
