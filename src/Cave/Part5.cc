#include <iostream>

#include "Cave.h"

using namespace s21;

solve_stack Cave::ShortestPath(point start, point end) {
    // Create a 2D array to keep track of visited cells and initialize all values to false
    bool visited[x_][y_];
    for (int i = 0; i < x_; i++) {
        for (int j = 0; j < y_; j++) {
            visited[i][j] = false;
        }
    }

    // Create a queue for BFS
    std::queue<point> q;

    // Enqueue the starting cell
    q.push(start);

    // Mark the starting cell as visited
    visited[start.first][start.second] = true;

    // Create a 2D array to keep track of parent cells
    point parent[x_][y_];
    for (int i = 0; i < x_; i++) {
        for (int j = 0; j < y_; j++) {
            parent[i][j] = point(-1, -1);
        }
    }

    // BFS algorithm
    while (!q.empty()) {
        // Dequeue a cell from the queue
        point curr = q.front();
        q.pop();

        // If the dequeued cell is the destination cell, backtrack to find the path and return it
        if (curr == end) {
            solve_stack path;
            while (curr != point(-1, -1)) {
                path.push(curr);
                curr = parent[curr.first][curr.second];
            }
            // reverse(path.begin(), path.end());
            return path;
        }

        // Explore the 4 neighboring cells (up, right, down, left)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            // Check if the neighboring cell is within the bounds of the cave
            if (nx >= 0 && nx < x_ && ny >= 0 && ny < y_) {
                // Check if the neighboring cell is not a wall and has not been visited
                if (!cave_[nx][ny] && !visited[nx][ny]) {
                    // Mark the neighboring cell as visited
                    visited[nx][ny] = true;

                    // Enqueue the neighboring cell
                    q.push(point(nx, ny));

                    // Set the parent of the neighboring cell
                    parent[nx][ny] = curr;
                }
            }
        }
    }

    // If there is no path from the starting cell to the destination cell, return an empty vector
    return solve_stack();
}