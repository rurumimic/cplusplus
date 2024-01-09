#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include <memory>

#include "maze.hpp"
#include "maze_factory.hpp"

class MazeGame {
 public:
  std::unique_ptr<Maze> CreateMaze();
  std::unique_ptr<Maze> CreateMaze(MazeFactory& factory);
};

#endif  // MAZE_GAME_H
