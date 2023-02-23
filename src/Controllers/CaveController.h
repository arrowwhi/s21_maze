#pragma once

#include "../Cave/Cave.h"

#include <QObject>

namespace s21 {

class CaveController : public QObject {
    Q_OBJECT
    Cave *cave_ = nullptr;
    public:
        CaveController() noexcept {}
        CaveController(uint x, uint y, int birth_limit, int death_limit) noexcept {
            cave_ = new Cave(x, y, birth_limit, death_limit);
        }
        void Create(uint x, uint y, double init_chance, int birth_limit, int death_limit) {
            delete cave_;
            cave_ = new Cave(x, y, init_chance, birth_limit, death_limit);
        }
        cave_size FromFile(std::string path, int birth_limit, int death_limit) {
            if (path != "") {
                delete cave_;
                cave_ = new Cave(path, birth_limit, death_limit);
            }
            return cave_->GetSize();
        }
        void Save(std::string path) {
            cave_->Save(path);
        }
        bool Update() {
            return cave_->Update();
        }
        bool GetLive(uint y, uint x) {
            return cave_->GetLive(y, x);
        }
        bool SetWall(uint y, uint x) {
            return cave_->SetWall(y, x);
        }
        bool SetAir(uint y, uint x) {
            return cave_->SetAir(y, x);
        }
        ~CaveController() noexcept { delete cave_; }
        solve_stack ShortestPath(point start, point end) {
            return cave_->ShortestPath(start, end);
        }

    public slots:
        void SetBirthLimit(int birth_limit) {
            cave_->SetBirthLimit(birth_limit);
        }
        void SetDeathLimit(int death_limit) {
            cave_->SetDeathLimit(death_limit);
        }
};

}  // namespace s21
