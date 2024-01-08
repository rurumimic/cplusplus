#include "EnchantedRoom.h"

EnchantedRoom::EnchantedRoom(int n, std::unique_ptr<Spell> spell)
    : Room(n), _spell(std::move(spell)) {}
