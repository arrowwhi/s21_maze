#pragma once

#include "../helpers/helpers.h"
#include "../maze_v2/maze.h"

namespace s21 {

class MazeController : public QObject {
  Maze *maze_ = nullptr;

 public:
  MazeController() noexcept {}
  MazeController(int x, int y) noexcept {
    maze_ = new Maze(y, x);
    maze_->Generate();
  }
  void Create(int x, int y) {
    delete maze_;
    maze_ = new Maze(y, x);
    maze_->Generate();
  }
  view_size FromFile(std::string path) {
    if (path != "") {
      delete maze_;
      maze_ = new Maze();
      maze_->FromFile(path);
    }
    return GetSize();
  }
  view_size GetSize() { return view_size(maze_->GetRows(), maze_->GetCols()); }
  std::pair<bool, bool> GetCell(int y, int x) { return maze_->GetCell(y, x); }
  ~MazeController() noexcept { delete maze_; }
  const solve_stack &ShortestPath(point start, point end) {
    maze_->MazeSolve(start, end);
    return maze_->GetSolve();
  }
};

}  // namespace s21
