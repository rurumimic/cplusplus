#ifndef ENCHANTED_ROOM_H
#define ENCHANTED_ROOM_H

#include "Room.h"
#include "Spell.h"

class EnchantedRoom : public Room {
 public:
  EnchantedRoom() = delete;
  EnchantedRoom(int n, std::unique_ptr<Spell> spell);
  ~EnchantedRoom() = default;

  EnchantedRoom(const EnchantedRoom&) = delete;             // copy constructor
  EnchantedRoom(EnchantedRoom&&) = delete;                  // move constructor
  EnchantedRoom& operator=(const EnchantedRoom&) = delete;  // copy assignment
  EnchantedRoom& operator=(EnchantedRoom&&) = delete;       // move assignment

 private:
  std::unique_ptr<Spell> _spell;
};

#endif  // ENCHANTED_ROOM_H
