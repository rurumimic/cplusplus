#include "door_needing_spell.hpp"

DoorNeedingSpell::DoorNeedingSpell(Room* r1, Room* r2) : Door(r1, r2) {}

void DoorNeedingSpell::Enter() {}

Room* DoorNeedingSpell::OtherSideFrom(Room* room) { return nullptr; }
