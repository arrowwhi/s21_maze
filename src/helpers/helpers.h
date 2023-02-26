#pragma once

#include <stack>

namespace s21 {


/*!
    \brief Typedefs used in the Cave class for convenience and readability.

    - `point`: represents a coordinate on the cave map, and is defined as a `std::pair<int, int>`.
    - `solve_stack`: represents a stack of `point` objects used to keep track of the current path during pathfinding, and is defined as a `std::stack<point>`.
    - `uint`: represents an unsigned integer used to specify the dimensions of the cave, and is defined as an `unsigned int`.
    - `view_size`: represents the size of the current view of the cave, and is defined as a `std::pair<int, int>`.
*/
typedef std::pair<int, int> point;
typedef std::stack<point> solve_stack;
typedef unsigned int uint;
typedef std::pair<int, int> view_size;

}  // namespace s21
