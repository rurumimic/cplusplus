#ifndef DOOR_NEEDING_SPEEL_H
#define DOOR_NEEDING_SPEEL_H

#include "Door.h"

class Room;

class DoorNeedingSpell : public Door {
 public:
  DoorNeedingSpell(Room* r1, Room* r2);
};

#endif  // DOOR_NEEDING_SPEEL_H
