#include "Cave.h"

using namespace s21;

Cave::Cave(uint x, uint y, double init_chance, int birth_limit, int death_limit)\
        noexcept : x_(x), y_(y), birth_limit_(birth_limit), death_limit_(death_limit) {
    std::default_random_engine generator(std::random_device{}());
    std::bernoulli_distribution distribution(init_chance);
    Allocate(x, y, [&]{ return distribution(generator); });
}

Cave::Cave(uint x, uint y, int birth_limit, int death_limit) noexcept :\
            x_(x), y_(y), birth_limit_(birth_limit), death_limit_(death_limit) {
    Allocate(x, y, []{ return false; });
}

Cave::Cave(std::string path, int birth_limit, int death_limit) :
        birth_limit_(birth_limit), death_limit_(death_limit) {
    std::fstream file(path);
    if (!file) return;
    file >> x_;
    file >> y_;
    Allocate(x_, y_, [&]{
        if (file) {
            bool cell;
            file >> cell;
            return cell;
        }
        return false;
    });
    file.close();
}

void Cave::Save(std::string path) {
    std::ofstream file(path + ".mzcv");
    if (!file) return;
    file << x_ << " " << y_ << "\n";
    for (uint i = 0; i < y_; i++) {
        for (uint j = 0; j < x_; j++) {
            file << cave_[i][j] << " ";
        }
        file << "\n";
    }
    file.close();
}

void Cave::Allocate(uint x, uint y, std::function<bool(void)> value_func) {
    cave_ = new bool*[y];
    for (uint k = 0; k < y_; k++) {
        cave_[k] = new bool[x];
        std::generate_n(cave_[k], x, value_func);
    }
}

Cave::~Cave() noexcept {
    if (x_ != 0) {
        for (uint k = 0; k < y_; k++ ) {
            delete[] cave_[k];
        }
    }
    if (y_ != 0)
        delete[] cave_;
}

void Cave::SetBirthLimit(int birth_limit) {
    birth_limit_ = birth_limit;
}

void Cave::SetDeathLimit(int death_limit) {
    death_limit_ = death_limit;
}

bool Cave::GetLive(uint y, uint x) const {
    if (x >= x_ || y >= y_)
        return false;
    return cave_[y][x];
}

bool Cave::SetWall(uint y, uint x) {
    if (x >= x_ || y >= y_) return false;
    bool ret = cave_[y][x];
    cave_[y][x] = true;
    return !ret;
}

bool Cave::SetAir(uint y, uint x) {
    if (x >= x_ || y >= y_) return false;
    bool ret = cave_[y][x];
    cave_[y][x] = false;
    return ret;
}

bool Cave::Update() {
    std::vector<std::pair<uint, uint>> live_cells, dead_cells;

    // Find all live and dead cells that need to be updated
    for (uint i = 0; i < y_; i++) {
        for (uint j = 0; j < x_; j++) {
            int live_neighbors = CountLiveNeighbors(i, j);
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
    if (live_cells.size() == 0 && live_cells.size() == 0) {
        return true;
    }
    // Update the state of the cells
    for (auto &cell : live_cells) {
        cave_[cell.first][cell.second] = false;
    }
    for (auto &cell : dead_cells) {
        cave_[cell.first][cell.second] = true;
    }
    return false;
}

int Cave::CountLiveNeighbors(uint i, uint j) {
    int live_neighbors = 0;
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
