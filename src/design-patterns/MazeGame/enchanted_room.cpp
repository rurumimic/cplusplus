#include "enchanted_room.hpp"

EnchantedRoom::EnchantedRoom(int n, std::unique_ptr<Spell> spell)
    : Room(n), _spell(std::move(spell)) {}
