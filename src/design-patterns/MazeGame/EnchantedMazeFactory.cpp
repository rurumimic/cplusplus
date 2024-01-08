#include "EnchantedMazeFactory.h"

#include "Spell.h"

EnchantedMazeFactory::EnchantedMazeFactory() {
  std::cout << "Init EnchantedMazeFactory()" << std::endl;
}

std::unique_ptr<Room> EnchantedMazeFactory::MakeRoom(int n) const {
  return std::make_unique<Room>(n);
}

std::shared_ptr<Door> EnchantedMazeFactory::MakeDoor(Room* r1, Room* r2) const {
  return std::make_shared<Door>(r1, r2);
}

std::unique_ptr<Spell> EnchantedMazeFactory::CastSpell() const {
  return std::make_unique<Spell>();
}
