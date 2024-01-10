#include "room_with_a_bomb.hpp"

#include <iostream>

RoomWithABomb::RoomWithABomb(int RoomNo, bool bombed)
    : Room(RoomNo), _bomb(bombed) {
  std::cout << "Init RoomWithABomb()" << std::endl;
}
