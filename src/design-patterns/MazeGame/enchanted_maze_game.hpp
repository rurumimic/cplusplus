#ifndef ENCHANTED_MAZE_GAME_H
#define ENCHANTED_MAZE_GAME_H

#include "maze_game.hpp"

class EnchantedMazeGame : public MazeGame {
 public:
  EnchantedMazeGame() = default;
  ~EnchantedMazeGame() = default;

  EnchantedMazeGame(const EnchantedMazeGame&) = delete;
  EnchantedMazeGame(EnchantedMazeGame&&) = delete;
  EnchantedMazeGame& operator=(const EnchantedMazeGame&) = delete;
  EnchantedMazeGame& operator=(EnchantedMazeGame&&) = delete;
};

#endif  // ENCHANTED_MAZE_GAME_H
