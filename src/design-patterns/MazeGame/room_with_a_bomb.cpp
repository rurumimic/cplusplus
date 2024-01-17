#include "room_with_a_bomb.hpp"

#include <iostream>

RoomWithABomb::RoomWithABomb(const int RoomNo, const bool bombed)
    : Room(RoomNo), _bomb(bombed) {
  std::cout << "Init RoomWithABomb()" << std::endl;
}
