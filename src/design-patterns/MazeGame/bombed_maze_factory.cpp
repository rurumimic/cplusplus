#include "bombed_maze_factory.hpp"

#include <iostream>

#include "bombed_wall.hpp"
#include "room_with_a_bomb.hpp"

BombedMazeFactory::BombedMazeFactory() {
  std::cout << "Init BombedMazeFactory()" << std::endl;
}

std::unique_ptr<Maze> BombedMazeFactory::MakeMaze() const {
  return std::make_unique<Maze>();
}

std::unique_ptr<Wall> BombedMazeFactory::MakeWall() const {
  return std::make_unique<BombedWall>();
}

std::unique_ptr<Room> BombedMazeFactory::MakeRoom(int n) const {
  return std::make_unique<RoomWithABomb>(n);
}

std::shared_ptr<Door> BombedMazeFactory::MakeDoor(Room* r1, Room* r2) const {
  return std::make_shared<Door>(r1, r2);
}
