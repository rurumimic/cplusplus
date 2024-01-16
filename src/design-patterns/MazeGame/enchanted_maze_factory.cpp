#include "enchanted_maze_factory.hpp"

#include <iostream>

#include "door_needing_spell.hpp"
#include "enchanted_room.hpp"

EnchantedMazeFactory::EnchantedMazeFactory() {
  std::cout << "Init EnchantedMazeFactory()" << std::endl;
}

std::unique_ptr<Maze> EnchantedMazeFactory::MakeMaze() const {
  return std::make_unique<Maze>();
}

std::unique_ptr<Wall> EnchantedMazeFactory::MakeWall() const {
  return std::make_unique<Wall>();
}

std::unique_ptr<Room> EnchantedMazeFactory::MakeRoom(int n) const {
  return std::make_unique<EnchantedRoom>(n, std::move(CastSpell()));
}

std::shared_ptr<Door> EnchantedMazeFactory::MakeDoor(Room* r1, Room* r2) const {
  return std::make_shared<DoorNeedingSpell>(r1, r2);
}

std::unique_ptr<Spell> EnchantedMazeFactory::CastSpell() const {
  return std::make_unique<Spell>();
}
