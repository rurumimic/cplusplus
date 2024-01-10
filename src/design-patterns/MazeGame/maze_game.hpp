#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include <memory>

#include "maze.hpp"
#include "maze_factory.hpp"

class MazeGame {
 public:
  MazeGame() = default;
  ~MazeGame() = default;

  MazeGame(const MazeGame&) = delete;             // copy constructor
  MazeGame(MazeGame&&) = delete;                  // move constructor
  MazeGame& operator=(const MazeGame&) = delete;  // copy assignment
  MazeGame& operator=(MazeGame&&) = delete;       // move assignment

  std::unique_ptr<Maze> CreateMaze();
  std::unique_ptr<Maze> CreateMaze(MazeFactory& factory);
};

#endif  // MAZE_GAME_H
