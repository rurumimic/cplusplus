#ifndef DOOR_H
#define DOOR_H

#include "map_site.hpp"
#include "room.hpp"

class Door : public MapSite {
 public:
  Door() = delete;
  Door(Room* r1, Room* r2);
  ~Door() = default;

  Door(const Door &) = delete;             // copy constructor
  Door(Door &&) = delete;                  // move constructor
  Door &operator=(const Door &) = delete;  // copy assignment
  Door &operator=(Door &&) = delete;       // move assignment

  void Enter() override;
  Room *OtherSideFrom(const Room *) const;

 protected:
  Room* _room1;
  Room* _room2;
  bool _isOpen;
};

#endif  // DOOR_H
