#pragma once

#include <iostream>

#include <random>
#include <algorithm>
#include <functional>
#include <fstream>
#include <queue>

#include "../helpers/helpers.h"

namespace s21 {


/*!
    \brief Class for creating and updating caves using cellular automaton generation.
In many games there is a need for branching locations, such as caves.
They can be created by generation using the cellular automaton.
This kind of generation uses an idea similar to the Game of Life.
The idea of the proposed algorithm consists of implementing only two steps: first, the whole field is filled randomly with walls - i.e.,
for each cell it is randomly determined whether it will be free or impassable - and then the map state is updated several times according to the conditions,
similar to the birth/death ones in the Game of Life.
The rules are simpler than in the Game of Life - there are two special variables, one for "birth" of "dead" cells (the "birth" limit) and one for destruction of "live" cells (the "death" limit).
If "live" cells are surrounded by "live" cells, the number of which is less than the "death" limit, they "die".
In the same way, if "dead" cells are next to "live" cells, the number of which is greater than the "birth" limit, they become "live".
*/
class Cave {
    uint x_ = 0, y_ = 0;
    bool **cave_;
    int birth_limit_, death_limit_;
    int CountLiveNeighbors(int i, int j);
    void Allocate(uint x, uint y, std::function<bool(void)> value_func);
    solve_stack path_;

    public:
        /*!
            \brief Constructor to create a cave with given parameters and random initial state
            \param x The width of the cave
            \param y The height of the cave
            \param init_chance The initial probability of a cell being a wall
            \param birth_limit The birth limit for cells
            \param death_limit The death limit for cells
        */
        Cave(uint x, uint y, double init_chance, int birth_limit, int death_limit) noexcept;
        /*!
            \brief Constructor to create a cave with given parameters and empty initial state
            \param x The width of the cave
            \param y The height of the cave
            \param birth_limit The birth limit for cells
            \param death_limit The death limit for cells
        */
        Cave(uint x, uint y, int birth_limit, int death_limit) noexcept;
        /*!
            \brief Constructor to create a cave from a file .mzcv
            \param path The path to the file containing the cave
            \param birth_limit The birth limit for cells
            \param death_limit The death limit for cells
        */
        Cave(std::string path, int birth_limit, int death_limit);
        /*!
            \brief Default constructor to create an empty cave
        */
        Cave() noexcept {}
        /*!
            \brief Destructor to free memory used by the cave
        */
        ~Cave() noexcept;
        /*!
            \brief Get the state of a cell in the cave
            \param y The y-coordinate of the cell
            \param x The x-coordinate of the cell
            \return The state of the cell (true if it is a wall, false if it is air)
        */
        bool GetLive(uint y, uint x) const;
        /*!
            \brief Update the state of the cave based on the birth/death rules
            \return False if any cell state was updated, true otherwise
        */
        bool Update();
        /*!
            \brief Set the birth limit for cells
            \param birth_limit The new birth limit for cells
        */
        void SetBirthLimit(int birth_limit);
        /*!
            \brief Set the death limit for cells
            \param death_limit The new death limit for cells
        */
        void SetDeathLimit(int death_limit);
        /*!
            \brief Set a cell in the cave to be a wall
            \param y The y-coordinate of the cell
            \param x The x-coordinate of the cell
            \return True if the cell state was updated, false otherwise
        */
        bool SetWall(uint y, uint x);
        /*!
            \brief Set a cell in the cave to be air
            \param y The y-coordinate of the cell
            \param x The x-coordinate of the cell
            \return True if the cell state was updated, false otherwise
        */
        bool SetAir(uint y, uint x);
        /*!
            \brief Find the shortest path between two points in the cave
            \param start The starting point for the path
            \param end The ending point for the path
            \return A constant reference to the solve_stack data member storing the path
        */
        const solve_stack &ShortestPath(point start, point end);
        /*!
            \brief Get the size of the cave
            \return The view_size object representing the size of the cave
        */
        view_size GetSize() const { return view_size(x_, y_); }
        /*!
            \brief Save the cave to a file
            \param path The path to the file to save the cave in
        */
        void Save(std::string path);
        /*!
            \brief Print the cave to the console
        */
        void Print();
};

}  // namespace s21
