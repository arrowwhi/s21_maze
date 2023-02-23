#pragma once

#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
// #include <ostream>
#include <fstream>
#include <queue>

#include "../Helpers/Helpers.h"

namespace s21 {

typedef std::pair<int, int> cave_size;

class Cave {
    uint x_ = 0, y_ = 0;
    bool **cave_;
    int birth_limit_, death_limit_;
    int CountLiveNeighbors(uint i, uint j);
    void Allocate(uint x, uint y, std::function<bool(void)> value_func);

    public:
        Cave(uint x, uint y, double init_chance, int birth_limit, int death_limit) noexcept;
        Cave(uint x, uint y, int birth_limit, int death_limit) noexcept;
        Cave(std::string path, int birth_limit, int death_limit);
        Cave() noexcept {}
        ~Cave() noexcept;
        bool GetLive(uint y, uint x) const;
        bool Update();
        void SetBirthLimit(int birth_limit);
        void SetDeathLimit(int death_limit);
        bool SetWall(uint y, uint x);
        bool SetAir(uint y, uint x);
        solve_stack ShortestPath(point start, point end);
        cave_size GetSize() const { return cave_size(x_, y_); }
        void Save(std::string path);

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
