#include "EnchantedMazeFactory.h"

#include <iostream>

#include "Spell.h"

EnchantedMazeFactory::EnchantedMazeFactory() {
  std::cout << "Init EnchantedMazeFactory()" << std::endl;
}

Spell* EnchantedMazeFactory::CastSpell() const {
  return new Spell;
}
