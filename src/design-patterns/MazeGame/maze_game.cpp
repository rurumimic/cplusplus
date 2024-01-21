#include "maze_game.hpp"

#include <memory>

std::unique_ptr<Maze> MazeGame::CreateMaze() {
  std::unique_ptr<Maze> aMaze = std::make_unique<Maze>();

  std::unique_ptr<Room> r1 = std::make_unique<Room>(1);
  std::unique_ptr<Room> r2 = std::make_unique<Room>(2);
  std::shared_ptr<Door> aDoor = std::make_shared<Door>(r1.get(), r2.get());

  r1->SetSide(Direction::North, std::move(std::make_unique<Wall>()));
  r1->SetSide(Direction::East, aDoor);
  r1->SetSide(Direction::South, std::move(std::make_unique<Wall>()));
  r1->SetSide(Direction::West, std::move(std::make_unique<Wall>()));

  r2->SetSide(Direction::North, std::move(std::make_unique<Wall>()));
  r2->SetSide(Direction::East, std::move(std::make_unique<Wall>()));
  r2->SetSide(Direction::South, std::move(std::make_unique<Wall>()));
  r2->SetSide(Direction::West, aDoor);

  aMaze->AddRoom(std::move(r1));
  aMaze->AddRoom(std::move(r2));

  return std::move(aMaze);
}

std::unique_ptr<Maze> MazeGame::CreateMaze(MazeFactory& factory) {
  std::unique_ptr<Maze> aMaze = factory.MakeMaze();

  std::unique_ptr<Room> r1 = factory.MakeRoom(1);
  std::unique_ptr<Room> r2 = factory.MakeRoom(2);
  std::shared_ptr<Door> aDoor = factory.MakeDoor(r1.get(), r2.get());

  r1->SetSide(Direction::North, factory.MakeWall());
  r1->SetSide(Direction::East, aDoor);
  r1->SetSide(Direction::South, factory.MakeWall());
  r1->SetSide(Direction::West, factory.MakeWall());

  r2->SetSide(Direction::North, factory.MakeWall());
  r2->SetSide(Direction::East, factory.MakeWall());
  r2->SetSide(Direction::South, factory.MakeWall());
  r2->SetSide(Direction::West, aDoor);

  aMaze->AddRoom(std::move(r1));
  aMaze->AddRoom(std::move(r2));

  return aMaze;
}

std::unique_ptr<Maze> MazeGame::CreateMaze(MazeBuilder& builder) {
  builder.BuildMaze();

  builder.BuildRoom(1);
  builder.BuildRoom(2);
  builder.BuilderDoor(1, 2);

  return builder.GetMaze();
}

std::unique_ptr<Maze> MazeGame::CreateComplexMaze(MazeBuilder& builder) {
  for (int i = 1; i < 1000; ++i) {
    builder.BuildRoom(i);
  }

  return builder.GetMaze();
}
