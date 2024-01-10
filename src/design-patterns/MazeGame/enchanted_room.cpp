#include "enchanted_room.hpp"

#include <iostream>

EnchantedRoom::EnchantedRoom(int n, std::unique_ptr<Spell> spell)
    : Room(n), _spell(std::move(spell)) {
  std::cout << "Init EnchantedRoom()" << std::endl;
}
