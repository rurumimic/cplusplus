#ifndef CAST_SPELL_H
#define CAST_SPELL_H

#include "spell.hpp"

class CastSpell : public Spell {
 public:
  CastSpell() = default;
  ~CastSpell() = default;

  CastSpell(const CastSpell&) = delete;             // copy constructor
  CastSpell(CastSpell&&) = delete;                  // move constructor
  CastSpell& operator=(const CastSpell&) = delete;  // copy assignment
  CastSpell& operator=(CastSpell&&) = delete;       // move assignment
};

#endif  // CAST_SPELL_H
