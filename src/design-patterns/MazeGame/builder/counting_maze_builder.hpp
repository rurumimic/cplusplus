#ifndef COUNTING_MAZE_BUILDER_H
#define COUNTING_MAZE_BUILDER_H

#include <memory>

#include "maze_builder.hpp"

class CountingMazeBuilder : public MazeBuilder {
 public:
  CountingMazeBuilder();
  ~CountingMazeBuilder() = default;

  CountingMazeBuilder(const CountingMazeBuilder&) = delete;
  CountingMazeBuilder(CountingMazeBuilder&&) = delete;
  CountingMazeBuilder& operator=(const CountingMazeBuilder&) = delete;
  CountingMazeBuilder& operator=(CountingMazeBuilder&&) = delete;

  void BuildMaze() override;
  void BuildRoom(const int room) override;
  void BuilderDoor(const int roomFrom, const int roomTo) override;

  [[nodiscard]] std::unique_ptr<Maze> GetMaze() override;

  void AddWall(int room, Direction direction);

  void GetCounts(int& rooms, int& doors) const;

 private:
  int roomsCount;
  int doorsCount;
};

#endif  // COUNTING_MAZE_BUILDER_H
