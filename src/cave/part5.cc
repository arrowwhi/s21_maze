#include <iostream>

#include "cave.h"

using namespace s21;

// Returns the shortest path from start point to end point in the cave.
// Uses Breadth-First Search algorithm to find the path.
// Input: start (pair of integers representing starting point), end (pair of
// integers representing ending point) Output: const reference to a solve_stack
// containing the shortest path (if found), empty stack otherwise.
const solve_stack &Cave::ShortestPath(point start, point end) {
  path_ = solve_stack();

  // Mark all cells in the cave as not visited
  bool visited[x_][y_];
  for (int i = 0; i < x_; ++i) {
    for (int j = 0; j < y_; ++j) {
      visited[i][j] = false;
    }
  }

  // Create a queue for BFS and push the starting point to it
  std::queue<point> q;
  q.push(start);

  // Mark the starting point as visited and initialize its parent as (-1, -1)
  visited[start.first][start.second] = true;
  point parent[x_][y_];
  for (int i = 0; i < x_; ++i) {
    for (int j = 0; j < y_; ++j) {
      parent[i][j] = point(-1, -1);
    }
  }

  // Run BFS until the queue is empty or the end point is found
  while (!q.empty()) {
    point curr = q.front();
    q.pop();

    if (curr == end) {
      // Build the path by following the parent pointers
      while (curr != point(-1, -1)) {
        path_.push(curr);
        curr = parent[curr.first][curr.second];
      }
      return path_;
    }

    // Explore the neighbors of the current cell and add them to the queue if
    // they haven't been visited yet
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int nx = curr.first + dx[i];
      int ny = curr.second + dy[i];

      if (nx >= 0 && nx < y_ && ny >= 0 && ny < x_) {
        if (!cave_[nx][ny] && !visited[nx][ny]) {
          visited[nx][ny] = true;
          q.push(point(nx, ny));
          parent[nx][ny] = curr;
        }
      }
    }
  }
  // If the end point is not found, return an empty stack
  path_ = solve_stack();
  return path_;
}