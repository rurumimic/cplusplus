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

  void BuildMaze() final;
  void BuildRoom(const int room) final;
  void BuilderDoor(const int roomFrom, const int roomTo) final;

  [[nodiscard]] std::unique_ptr<Maze> GetMaze() final;

  void AddWall(int room, Direction direction);

  void GetCounts(int& rooms, int& doors) const;

 private:
  int roomsCount;
  int doorsCount;
};

#endif  // COUNTING_MAZE_BUILDER_H
