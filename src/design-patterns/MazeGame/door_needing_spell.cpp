#include "door_needing_spell.hpp"

#include <iostream>

DoorNeedingSpell::DoorNeedingSpell(Room* r1, Room* r2) : Door(r1, r2) {
  std::cout << "Init DoorNeedingSpell()" << std::endl;
}

void DoorNeedingSpell::Enter() {}

Room* DoorNeedingSpell::OtherSideFrom(const Room* room) const { return nullptr; }
