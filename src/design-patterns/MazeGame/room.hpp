#ifndef ROOM_H
#define ROOM_H

#include <array>
#include <memory>

#include "direction.hpp"
#include "map_site.hpp"

class Room : public MapSite {
 public:
  Room() = delete;
  Room(const int RoomNo);
  ~Room() = default;

  Room(const Room&) = delete;             // copy constructor
  Room(Room&&) = delete;                  // move constructor
  Room& operator=(const Room&) = delete;  // copy assignment
  Room& operator=(Room&&) = delete;       // move assignment

  [[nodiscard]] int GetRoomNumber() const;

  [[nodiscard]] MapSite* GetSide(Direction) const;
  void SetSide(Direction, std::shared_ptr<MapSite>);

  void Enter() override;

 private:
  std::array<std::shared_ptr<MapSite>, 4> _sides;
  int _roomNumber;
};

#endif  // ROOM_H
