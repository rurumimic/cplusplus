#include "standard_maze_builder.hpp"

#include <iostream>

#include "door.hpp"
#include "room.hpp"
#include "wall.hpp"

StandardMazeBuilder::StandardMazeBuilder() : currentMaze(nullptr) {
  std::cout << "Init StandardMazeBuilder()" << std::endl;
}

std::unique_ptr<Maze> StandardMazeBuilder::GetMaze() {
  std::cout << "StandardMazeBuilder::GetMaze()" << std::endl;

  return std::move(currentMaze);
}

Direction StandardMazeBuilder::CommonWall(const Room* room1,
                                          const Room* room2) {
  std::cout << "StandardMazeBuilder::CommonWall(" << room1->GetRoomNumber()
            << ", " << room2->GetRoomNumber() << ")" << std::endl;

  if (room1->GetRoomNumber() < room2->GetRoomNumber()) {
    return Direction::East;
  } else {
    return Direction::West;
  }
}

void StandardMazeBuilder::BuildMaze() {
  std::cout << "StandardMazeBuilder::BuildMaze()" << std::endl;

  currentMaze = std::make_unique<Maze>();
}
void StandardMazeBuilder::BuildRoom(const int room) {
  std::cout << "StandardMazeBuilder::BuildRoom()" << std::endl;

  if (!currentMaze->GetRoom(room)) {
    std::unique_ptr<Room> aRoom = std::make_unique<Room>(room);

    aRoom->SetSide(Direction::North, std::make_unique<Wall>());
    aRoom->SetSide(Direction::East, std::make_unique<Wall>());
    aRoom->SetSide(Direction::South, std::make_unique<Wall>());
    aRoom->SetSide(Direction::West, std::make_unique<Wall>());

    currentMaze->AddRoom(std::move(aRoom));
  }
}

void StandardMazeBuilder::BuilderDoor(const int roomFrom, const int roomTo) {
  std::cout << "StandardMazeBuilder::BuilderDoor()" << std::endl;

  Room* r1 = currentMaze->GetRoom(roomFrom);
  Room* r2 = currentMaze->GetRoom(roomTo);

  std::shared_ptr<Door> aDoor = std::make_shared<Door>(r1, r2);

  r1->SetSide(CommonWall(r1, r2), aDoor);
  r2->SetSide(CommonWall(r2, r1), aDoor);
}
