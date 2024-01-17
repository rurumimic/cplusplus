#include <iostream>

#include "bombed_maze_factory.hpp"
#include "config.h"
#include "enchanted_maze_factory.hpp"
#include "maze_game.hpp"

void version() {
  std::cout << "v" << PATTERNS_VERSION_MAJOR << "." << PATTERNS_VERSION_MINOR
            << std::endl;
}

void enchantedMazeGame() {
  std::cout << "EnchantedMazeGame" << std::endl;
  MazeGame mazeGame;
  EnchantedMazeFactory factory;
  std::unique_ptr<Maze> maze = mazeGame.CreateMaze(factory);

  Room* r1 = maze->GetRoom(1);
  std::cout << "Room " << r1->GetRoomNumber() << std::endl;
  std::cout << std::endl;
}

void bombedMazeGame() {
  std::cout << "BombedMazeGame" << std::endl;
  MazeGame mazeGame;
  BombedMazeFactory factory;
  std::unique_ptr<Maze> maze = mazeGame.CreateMaze(factory);

  Room* r1 = maze->GetRoom(1);
  std::cout << "Room " << r1->GetRoomNumber() << std::endl;
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  version();

  enchantedMazeGame();
  bombedMazeGame();

  return 0;
}
