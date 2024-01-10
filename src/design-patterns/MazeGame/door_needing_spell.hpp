#ifndef DOOR_NEEDING_SPEEL_H
#define DOOR_NEEDING_SPEEL_H

#include "door.hpp"

class DoorNeedingSpell : public Door {
 public:
  DoorNeedingSpell() = delete;
  DoorNeedingSpell(Room*, Room*);
  ~DoorNeedingSpell() = default;

  DoorNeedingSpell(const DoorNeedingSpell&) = delete;
  DoorNeedingSpell(DoorNeedingSpell&&) = delete;
  DoorNeedingSpell& operator=(const DoorNeedingSpell&) = delete;
  DoorNeedingSpell& operator=(DoorNeedingSpell&&) = delete;

  void Enter() override;
  Room* OtherSideFrom(Room*);

 protected:
  Room* _r1;
  Room* _r2;
  bool _is_open;
};

#endif  // DOOR_NEEDING_SPEEL_H
