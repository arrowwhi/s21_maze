#include "Cave.h"

Cave::Cave(unsigned x, unsigned y, double init_chance, unsigned birth_limit, unsigned death_limit) noexcept\
                    : x_(x), y_(y), birth_limit_(birth_limit), death_limit_(death_limit) {

    std::default_random_engine generator(std::random_device{}());
    std::bernoulli_distribution distribution(init_chance);

    cave_ = new bool*[y];
    for (unsigned k = 0; k < y_; k++) {
        cave_[k] = new bool[x];
        std::generate_n(cave_[k], x, [&]{ return distribution(generator); });
    }
}

Cave::~Cave() noexcept {
    if (x_ != 0) {
        for (unsigned k = 0; k < y_; k++ ) {
            delete[] cave_[k];
        }
    }
    if (y_ != 0)
        delete[] cave_;
}

bool Cave::getLive(unsigned x, unsigned y) const {
    if (x > x_ || y > y_)
        return false;
    return cave_[x][y];
}

void Cave::update() {
    std::vector<std::pair<unsigned, unsigned>> live_cells, dead_cells;

    // Find all live and dead cells that need to be updated
    for (unsigned i = 0; i < y_; i++) {
        for (unsigned j = 0; j < x_; j++) {
            unsigned live_neighbors = count_live_neighbors(i, j);
            if (cave_[i][j]) {
                if (live_neighbors < death_limit_) {
                    // cell dies
                    live_cells.emplace_back(i, j);
                }
            } else {
                if (live_neighbors > birth_limit_) {
                    // cell becomes live
                    dead_cells.emplace_back(i, j);
                }
            }
        }
    }

    // Update the state of the cells
    for (auto &cell : live_cells) {
        cave_[cell.first][cell.second] = false;
    }
    for (auto &cell : dead_cells) {
        cave_[cell.first][cell.second] = true;
    }
}

unsigned Cave::count_live_neighbors(unsigned i, unsigned j) {
    unsigned live_neighbors = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) continue;
            int row = i + k;
            int col = j + l;
            if (row < 0 || col < 0 || row >= y_ || col >= x_ || cave_[row][col]) live_neighbors++;
        }
    }
    return live_neighbors;
}
