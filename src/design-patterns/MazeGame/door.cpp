#include "door.hpp"

#include <iostream>

Door::Door(Room* r1, Room* r2) : _room1(r1), _room2(r2) {
  std::cout << "Init Door(" << r1->GetRoomNumber() << ", " << r2->GetRoomNumber() << ")"
            << std::endl;
}

void Door::Enter() {}

Room* Door::OtherSideFrom(Room* room) { return nullptr; }
