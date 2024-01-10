#ifndef ROOM_WITH_A_BOMB_H
#define ROOM_WITH_A_BOMB_H

#include "room.hpp"

class RoomWithABomb : public Room {
 public:
  RoomWithABomb() = delete;
  RoomWithABomb(int = 0, bool bombed = false);
  ~RoomWithABomb() = default;

  RoomWithABomb(const RoomWithABomb&) = delete;
  RoomWithABomb(RoomWithABomb&&) = delete;
  RoomWithABomb& operator=(const RoomWithABomb&) = delete;
  RoomWithABomb& operator=(RoomWithABomb&&) = delete;

 private:
  bool _bomb;
};

#endif  // ROOM_WITH_A_BOMB_H
