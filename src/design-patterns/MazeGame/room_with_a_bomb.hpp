#ifndef ROOM_WITH_A_BOMB_H
#define ROOM_WITH_A_BOMB_H

#include "room.hpp"

class RoomWithABomb : public Room {
 public:
  RoomWithABomb(int = 0, bool bombed = false);

 private:
  bool _bomb;
};

#endif  // ROOM_WITH_A_BOMB_H
