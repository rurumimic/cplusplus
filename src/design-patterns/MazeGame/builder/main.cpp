#include <iostream>

#include "config.h"
#include "maze_game.hpp"
#include "standard_maze_builder.hpp"
#include "counting_maze_builder.hpp"

void standardMazeGame() {
  std::cout << "StandardMazeGame" << std::endl;

  MazeGame mazeGame;
  StandardMazeBuilder builder;

  std::unique_ptr<Maze> maze = mazeGame.CreateMaze(builder);

  Room* r1 = maze->GetRoom(1);
  std::cout << "Room " << r1->GetRoomNumber() << std::endl;
  std::cout << std::endl;
}

void countingMazeGame() {
  std::cout << "CountingMazeGame" << std::endl;

  int rooms, doors;
  MazeGame mazeGame;
  CountingMazeBuilder builder;

  std::unique_ptr<Maze> maze = mazeGame.CreateMaze(builder);

  builder.GetCounts(rooms, doors);
  std::cout << "The maze has " << rooms << " rooms and " << doors << " doors"
            << std::endl;

  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  standardMazeGame();
  countingMazeGame();

  return 0;
}
