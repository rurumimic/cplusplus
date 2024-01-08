#ifndef ENCHANTED_MAZE_GAME_H
#define ENCHANTED_MAZE_GAME_H

#include "MazeGame.h"

class EnchantedMazeGame : public MazeGame {
 public:
  EnchantedMazeGame() = default;
  ~EnchantedMazeGame() = default;

  EnchantedMazeGame(const EnchantedMazeGame&) = delete;  // copy constructor
  EnchantedMazeGame(EnchantedMazeGame&&) = delete;       // move constructor
  EnchantedMazeGame& operator=(const EnchantedMazeGame&) =
      delete;  // copy assignment
  EnchantedMazeGame& operator=(EnchantedMazeGame&&) =
      delete;  // move assignment
};

#endif  // ENCHANTED_MAZE_GAME_H
