#ifndef DOOR_H
#define DOOR_H

#include "MapSite.h"
#include "Room.h"

class Door : public MapSite {
 public:
  Door(Room * = nullptr, Room * = nullptr);

  void Enter() override;
  Room *OtherSideFrom(Room *);

 private:
  Room *_room1;
  Room *_room2;
  bool _isOpen;
};

#endif  // DOOR_H
