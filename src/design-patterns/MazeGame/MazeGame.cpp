#include "MazeGame.h"

#include "Direction.h"
#include "Door.h"
#include "Maze.h"
#include "Room.h"
#include "Wall.h"

Maze* MazeGame::CreateMaze() {
  Maze* aMaze = new Maze;
  Room* r1 = new Room(1);
  Room* r2 = new Room(2);
  Door* theDoor = new Door(r1, r2);

  aMaze->AddRoom(r1);
  aMaze->AddRoom(r2);

  r1->SetSide(Direction::North, new Wall);
  r1->SetSide(Direction::East, new Wall);
  r1->SetSide(Direction::South, new Wall);
  r1->SetSide(Direction::West, new Wall);

  r2->SetSide(Direction::North, new Wall);
  r2->SetSide(Direction::East, new Wall);
  r2->SetSide(Direction::South, new Wall);
  r2->SetSide(Direction::West, new Wall);

  return aMaze;
}
