#pragma once

#include <stack>

namespace s21 {

/*!
    \brief Represents a coordinate on the cave map.
*/
typedef std::pair<int, int> point;

/*!
    \brief Represents a stack of point objects used to keep track of the current path during pathfinding.
*/
typedef std::stack<point> solve_stack;

/*!
    \brief Represents an unsigned integer used to specify the dimensions of the cave.
*/
typedef unsigned int uint;

/*!
    \brief Represents the size of the current view of the cave.
*/
typedef std::pair<int, int> view_size;

}  // namespace s21
