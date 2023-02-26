#pragma once

#include <iostream>

#include <random>
#include <algorithm>
#include <functional>
#include <fstream>
#include <queue>

#include "../Helpers/Helpers.h"

namespace s21 {

// typedef std::pair<int, int> cave_size;

class Cave {
    uint x_ = 0, y_ = 0;
    bool **cave_;
    int birth_limit_, death_limit_;
    int CountLiveNeighbors(int i, int j);
    void Allocate(uint x, uint y, std::function<bool(void)> value_func);
    solve_stack path_;

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
        const solve_stack &ShortestPath(point start, point end);
        view_size GetSize() const { return view_size(x_, y_); }
        void Save(std::string path);

        void Print();
};

}  // namespace s21
