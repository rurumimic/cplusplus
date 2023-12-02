#include "EnchantedMazeFactory.h"

#include <iostream>

#include "Spell.h"

EnchantedMazeFactory::EnchantedMazeFactory() {
  std::cout << "EnchantedMazeFactory()" << std::endl;
}

Spell* EnchantedMazeFactory::CastSpell() const {
  std::cout << "CastSpell()" << std::endl;

  return new Spell;
}