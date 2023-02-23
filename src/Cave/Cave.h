#include <iostream>
#include <random>
#include <algorithm>

class Cave {
    unsigned x_ = 0, y_ = 0;
    bool **cave_;
    unsigned birth_limit_, death_limit_;
    unsigned count_live_neighbors(unsigned i, unsigned j);
    public:
        Cave(unsigned x, unsigned y, double init_chance, unsigned birth_limit, unsigned death_limit) noexcept;
        Cave() noexcept {}
        ~Cave() noexcept;
        bool getLive(unsigned x, unsigned y) const;
        void update();
        void print() {
            for (int k = 0; k < y_; k++) {
                for (int g = 0; g < x_; g++) {
                    std::cout << cave_[k][g] << " ";
                }
                std::cout << "\n";
            }
        }
};