#pragma once

#include "../labyrinth_generation/lab_gen.h"
#include "../Helpers/Helpers.h"

namespace s21 {

class MazeController : public QObject {
    Labyrinth *maze_ = nullptr;
    public:
        MazeController() noexcept {}
        MazeController(int x, int y) noexcept {
            maze_ = new Labyrinth(y, x);
            maze_->Generate();
        }
        void Create(int x, int y) {
            delete maze_;
            maze_ = new Labyrinth(y, x);
            maze_->Generate();
        }
        view_size FromFile(std::string path) {
            if (path != "") {
                delete maze_;
                maze_ = new Labyrinth();
                maze_->FromFile(path);
            }
            return GetSize();
        }
        view_size GetSize() {
            return view_size(maze_->GetRows(), maze_->GetCols());
        }
        std::pair<bool, bool> GetCell(int y, int x) {
            return maze_->GetCell(y, x);
        }
        ~MazeController() noexcept { delete maze_; }
        const solve_stack &ShortestPath(point start, point end) {
            maze_->LabyrinthSolve(start, end);
            return maze_->GetSolve();
        }
};

}  // namespace s21
