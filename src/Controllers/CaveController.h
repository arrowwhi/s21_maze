#pragma once

#include "../Cave/Cave.h"

#include <QObject>

namespace s21 {

class CaveController : public QObject {
    Q_OBJECT
    Cave *cave_ = nullptr;
    // void DelCave() { if (cave_ != nullptr) delete cave_; }
    public:
        CaveController() noexcept {}
        CaveController(unsigned x, unsigned y, int birth_limit, int death_limit) noexcept {
            cave_ = new Cave(x, y, birth_limit, death_limit);
        }
        void Create(unsigned x, unsigned y, double init_chance, int birth_limit, int death_limit) {
            delete cave_;
            cave_ = new Cave(x, y, init_chance, birth_limit, death_limit);
        }
        void Update() {
            cave_->Update();
        }
        bool GetLive(unsigned y, unsigned x) {
            return cave_->GetLive(y, x);
        }
        bool SetWall(unsigned y, unsigned x) {
            return cave_->SetWall(y, x);
        }
        bool SetAir(unsigned y, unsigned x) {
            return cave_->SetAir(y, x);
        }
        ~CaveController() noexcept { delete cave_; }
        std::stack<std::pair<int, int>> ShortestPath(std::pair<int, int> start, std::pair<int, int> end) {
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
