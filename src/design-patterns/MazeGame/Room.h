#ifndef ROOM_H
#define ROOM_H

#include <array>

#include "Direction.h"
#include "MapSite.h"

class Room : public MapSite {
 public:
  Room(int RoomNo);

  int GetRoomNumber();

  MapSite *GetSide(Direction) const;
  void SetSide(Direction, MapSite *);

  void Enter() override;

 private:
  std::array<MapSite *, 4> _sides;
  int _roomNumber;
};

#endif  // ROOM_H
