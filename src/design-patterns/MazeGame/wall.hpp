#ifndef WALL_H
#define WALL_H

#include "map_site.hpp"

class Wall : public MapSite {
 public:
  Wall();
  ~Wall() = default;

  Wall(const Wall&) = delete;             // copy constructor
  Wall(Wall&&) = delete;                  // move constructor
  Wall& operator=(const Wall&) = delete;  // copy assignment
  Wall& operator=(Wall&&) = delete;       // move assignment

  void Enter() override;
};

#endif  // WALL_H
