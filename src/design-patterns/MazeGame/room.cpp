#include "room.hpp"

#include <iostream>

#include "direction.hpp"

Room::Room(const int RoomNo) : _roomNumber(RoomNo) {
  std::cout << "Init Room(" << _roomNumber << ")" << std::endl;
}

int Room::GetRoomNumber() const {
  return _roomNumber;
}

MapSite* Room::GetSide(Direction direction) const {
  auto index = static_cast<std::size_t>(direction);
  return _sides[index].get();
}

void Room::SetSide(Direction direction, std::shared_ptr<MapSite> mapSite) {
  auto index = static_cast<std::size_t>(direction);
  _sides[index] = mapSite;
}

void Room::Enter() {}
