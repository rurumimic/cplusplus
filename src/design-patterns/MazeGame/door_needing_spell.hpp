#ifndef DOOR_NEEDING_SPEEL_H
#define DOOR_NEEDING_SPEEL_H

#include "door.hpp"

class DoorNeedingSpell : public Door {
 public:
  DoorNeedingSpell() = delete;
  DoorNeedingSpell(Room*, Room*);
  ~DoorNeedingSpell() = default;

  DoorNeedingSpell(const DoorNeedingSpell&) = delete;  // copy constructor
  DoorNeedingSpell(DoorNeedingSpell&&) = delete;       // move constructor
  DoorNeedingSpell& operator=(const DoorNeedingSpell&) =
      delete;                                                // copy assignment
  DoorNeedingSpell& operator=(DoorNeedingSpell&&) = delete;  // move assignment

  void Enter() override;
  Room *OtherSideFrom(Room *);

 protected:
  Room* _r1;
  Room* _r2;
  bool _is_open;
};

#endif  // DOOR_NEEDING_SPEEL_H
