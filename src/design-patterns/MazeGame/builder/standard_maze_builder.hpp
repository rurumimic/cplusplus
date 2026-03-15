#ifndef STANDARD_MAZE_BUILDER_H
#define STANDARD_MAZE_BUILDER_H

#include <memory>

#include "direction.hpp"
#include "maze_builder.hpp"

class StandardMazeBuilder : public MazeBuilder {
 public:
  StandardMazeBuilder();
  ~StandardMazeBuilder() = default;

  StandardMazeBuilder(const StandardMazeBuilder&) = delete;
  StandardMazeBuilder(StandardMazeBuilder&&) = delete;
  StandardMazeBuilder& operator=(const StandardMazeBuilder&) = delete;
  StandardMazeBuilder& operator=(StandardMazeBuilder&&) = delete;

  void BuildMaze() final;
  void BuildRoom(const int room) final;
  void BuilderDoor(const int roomFrom, const int roomTo) final;

  [[nodiscard]] std::unique_ptr<Maze> GetMaze() final;

 private:
  Direction CommonWall(const Room* const room1, const Room* const room2);
  std::unique_ptr<Maze> currentMaze;
};

#endif  // STANDARD_MAZE_BUILDER_H
