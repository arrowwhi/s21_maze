#pragma once

#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>

namespace s21 {

class Cave {
    unsigned x_ = 0, y_ = 0;
    bool **cave_ = nullptr;
    int birth_limit_, death_limit_;
    int CountLiveNeighbors(unsigned i, unsigned j);
    void Allocate(unsigned x, unsigned y, std::function<bool(void)> value_func);

    public:
        Cave(unsigned x, unsigned y, double init_chance, int birth_limit, int death_limit) noexcept;
        Cave(unsigned x, unsigned y, int birth_limit, int death_limit) noexcept;
        Cave() noexcept {}
        ~Cave() noexcept;
        bool GetLive(unsigned y, unsigned x) const;
        void Update();
        void SetBirthLimit(int birth_limit);
        void SetDeathLimit(int death_limit);
        bool SetWall(unsigned y, unsigned x);
        bool SetAir(unsigned y, unsigned x);
        std::stack<std::pair<int, int>> ShortestPath(std::pair<int, int> start, std::pair<int, int> end);

        void print() {
            for (int k = 0; k < y_; k++) {
                for (int g = 0; g < x_; g++) {
                    std::cout << cave_[k][g] << " ";
                }
                std::cout << "\n";
            }
        }
};

}  // namespace s21
