#include <iostream>

#include "Cave.h"

using namespace s21;

solve_stack Cave::ShortestPath(point start, point end) {
    bool visited[x_][y_];
    for (int i = 0; i < x_; ++i) {
        for (int j = 0; j < y_; ++j) {
            visited[i][j] = false;
        }
    }

    std::queue<point> q;
    q.push(start);

    visited[start.first][start.second] = true;

    point parent[x_][y_];
    for (int i = 0; i < x_; ++i) {
        for (int j = 0; j < y_; ++j) {
            parent[i][j] = point(-1, -1);
        }
    }

    while (!q.empty()) {
        point curr = q.front();
        q.pop();

        if (curr == end) {
            solve_stack path;
            while (curr != point(-1, -1)) {
                path.push(curr);
                curr = parent[curr.first][curr.second];
            }
            return path;
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx >= 0 && nx < x_ && ny >= 0 && ny < y_) {
                if (!cave_[nx][ny] && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push(point(nx, ny));
                    parent[nx][ny] = curr;
                }
            }
        }
    }
    return solve_stack();
}