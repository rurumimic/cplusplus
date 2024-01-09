#ifndef MAP_SITE_H
#define MAP_SITE_H

class MapSite {
 public:
  MapSite() = default;
  ~MapSite() = default;

  MapSite(const MapSite&) = delete;             // copy constructor
  MapSite(MapSite&&) = delete;                  // move constructor
  MapSite& operator=(const MapSite&) = delete;  // copy assignment
  MapSite& operator=(MapSite&&) = delete;       // move assignment

  virtual void Enter() = 0;
};

#endif  // MAP_SITE_H
