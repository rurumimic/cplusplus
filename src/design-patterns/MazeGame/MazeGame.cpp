#include "MazeGame.h"

#include "Direction.h"
#include "Door.h"
#include "Maze.h"
#include "MazeFactory.h"
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
  r1->SetSide(Direction::East, theDoor);
  r1->SetSide(Direction::South, new Wall);
  r1->SetSide(Direction::West, new Wall);

  r2->SetSide(Direction::North, new Wall);
  r2->SetSide(Direction::East, new Wall);
  r2->SetSide(Direction::South, new Wall);
  r2->SetSide(Direction::West, theDoor);

  return aMaze;
}

Maze* MazeGame::CreateMaze(MazeFactory& factory) {
  Maze* aMaze = factory.MakeMaze();
  Room* r1 = factory.MakeRoom(1);
  Room* r2 = factory.MakeRoom(2);
  Door* aDoor = factory.MakeDoor(r1, r2);

  aMaze->AddRoom(r1);
  aMaze->AddRoom(r2);

  r1->SetSide(Direction::North, factory.MakeWall());
  r1->SetSide(Direction::East, aDoor);
  r1->SetSide(Direction::South, factory.MakeWall());
  r1->SetSide(Direction::West, factory.MakeWall());

  r2->SetSide(Direction::North, factory.MakeWall());
  r2->SetSide(Direction::East, factory.MakeWall());
  r2->SetSide(Direction::South, factory.MakeWall());
  r2->SetSide(Direction::West, aDoor);

  return aMaze;
}

