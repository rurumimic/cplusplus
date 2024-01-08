#ifndef WALL_H
#define WALL_H

#include "MapSite.h"

class Wall : public MapSite {
 public:
  Wall() = default;
  ~Wall() = default;

  Wall(const Wall&) = delete;             // copy constructor
  Wall(Wall&&) = delete;                  // move constructor
  Wall& operator=(const Wall&) = delete;  // copy assignment
  Wall& operator=(Wall&&) = delete;       // move assignment

  void Enter() override;
};

#endif  // WALL_H
