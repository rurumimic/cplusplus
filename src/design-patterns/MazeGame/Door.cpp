#include "Door.h"

Door::Door(Room* r1, Room* r2) : _room1(r1), _room2(r2) {}

void Door::Enter() {}

Room* Door::OtherSideFrom(Room* room) { return nullptr; }
