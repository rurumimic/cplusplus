#ifndef SPELL_H
#define SPELL_H

class Spell {
 public:
  Spell() = default;
  ~Spell() = default;

  Spell(const Spell&) = delete;             // copy constructor
  Spell(Spell&&) = delete;                  // move constructor
  Spell& operator=(const Spell&) = delete;  // copy assignment
  Spell& operator=(Spell&&) = delete;       // move assignment
};

#endif  // SPELL_H
