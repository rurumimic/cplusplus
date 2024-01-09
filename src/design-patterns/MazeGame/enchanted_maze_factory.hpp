#ifndef ENCHANTED_MAZE_FACTORY_H
#define ENCHANTED_MAZE_FACTORY_H

#include <memory>

#include "maze_factory.hpp"
#include "spell.hpp"

class EnchantedMazeFactory : public MazeFactory {
 public:
  EnchantedMazeFactory();

  [[nodiscard]] std::unique_ptr<Room> MakeRoom(int n) const override;
  std::shared_ptr<Door> MakeDoor(Room* r1, Room* r2) const override;

 protected:
  [[nodiscard]] std::unique_ptr<Spell> CastSpell() const;
};

#endif  // ENCHANTED_MAZE_FACTORY_H
