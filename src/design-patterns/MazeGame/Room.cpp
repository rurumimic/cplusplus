#include "Room.h"
#include "Direction.h"

Room::Room(int RoomNo) : _roomNumber(RoomNo) {}

int Room::GetRoomNumber() { return _roomNumber; }

MapSite* Room::GetSide(Direction direction) {
  auto index = static_cast<std::size_t>(direction);
  return _sides[index].get();
}

void Room::SetSide(Direction direction, std::shared_ptr<MapSite> mapSite) {
  auto index = static_cast<std::size_t>(direction);
  _sides[index] = mapSite;
}

void Room::Enter() {}
