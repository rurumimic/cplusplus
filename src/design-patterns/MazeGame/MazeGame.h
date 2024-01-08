#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include <memory>

#include "Direction.h"
#include "Door.h"
#include "Maze.h"
#include "MazeFactory.h"
#include "Room.h"
#include "Wall.h"

class MazeGame {
 public:
  std::unique_ptr<Maze> CreateMaze();
  std::unique_ptr<Maze> CreateMaze(MazeFactory& factory);
};

#endif  // MAZE_GAME_H
