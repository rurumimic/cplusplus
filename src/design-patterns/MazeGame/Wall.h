#ifndef WALL_H
#define WALL_H

#include "MapSite.h"

class Wall : public MapSite {
 public:
  Wall() = default;

  void Enter() override;
};

#endif  // WALL_H
