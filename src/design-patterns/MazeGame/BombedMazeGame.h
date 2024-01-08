#ifndef BOMBED_MAZE_GAME_H
#define BOMBED_MAZE_GAME_H

#include "MazeGame.h"

class BombedMazeGame : public MazeGame {
 public:
  BombedMazeGame() = default;
  ~BombedMazeGame() = default;

  BombedMazeGame(const BombedMazeGame&) = delete;  // copy constructor
  BombedMazeGame(BombedMazeGame&&) = delete;       // move constructor
  BombedMazeGame& operator=(const BombedMazeGame&) = delete;  // copy assignment
  BombedMazeGame& operator=(BombedMazeGame&&) = delete;       // move assignment
};

#endif  // BOMBED_MAZE_GAME_H
