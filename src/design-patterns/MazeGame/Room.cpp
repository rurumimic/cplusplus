#include "Room.h"

Room::Room(int RoomNo) : _roomNumber(RoomNo) {}

MapSite* Room::GetSide(Direction direction) const {
  auto index = static_cast<std::size_t>(direction);
  return _sides[index];
}

void Room::SetSide(Direction direction, MapSite* mapSite) {
  auto index = static_cast<std::size_t>(direction);
  _sides[index] = mapSite;
}

void Room::Enter() {}
