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

  void BuildMaze() override;
  void BuildRoom(const int room) override;
  void BuilderDoor(const int roomFrom, const int roomTo) override;

  [[nodiscard]] std::unique_ptr<Maze> GetMaze() override;

 private:
  Direction CommonWall(const Room* room1, const Room* room2);
  std::unique_ptr<Maze> currentMaze;
};

#endif  // STANDARD_MAZE_BUILDER_H
