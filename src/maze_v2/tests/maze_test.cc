#include "../maze.h"

#include <gtest/gtest.h>

#include "../../helpers/helpers.h"

TEST(Maze, Creation) {
  s21::Maze maze(10, 10);
  maze.Generate();
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int ans =
          maze.MazeSolve(std::make_pair(i, j), std::make_pair(9 - i, 9 - j));
      ASSERT_FALSE(ans);
    }
  }
}

TEST(Maze, FromFile) {
  s21::Maze maze;
  bool err = maze.FromFile("test_4x4.mzcv");
  ASSERT_FALSE(err);
  err = maze.FromFile("test_10x10.mzcv");
  ASSERT_FALSE(err);
  err = maze.FromFile("test_20x20.mzcv");
  ASSERT_FALSE(err);
}

TEST(Maze, Solve) {
  s21::Maze maze;
  maze.FromFile("test_4x4.mzcv");
  maze.MazeSolve(std::make_pair(0, 0), std::make_pair(1, 0));
  auto out_stack = maze.GetSolve();
  s21::solve_stack std_stack;
  std_stack.emplace(std::make_pair(1, 0));
  std_stack.emplace(std::make_pair(1, 0));
  std_stack.emplace(std::make_pair(2, 0));
  std_stack.emplace(std::make_pair(2, 1));
  std_stack.emplace(std::make_pair(1, 1));
  std_stack.push(std::make_pair(0, 1));
  while (!out_stack.empty()) {
    ASSERT_EQ(out_stack.top().first, std_stack.top().first);
    ASSERT_EQ(out_stack.top().second, std_stack.top().second);
    std_stack.pop();
    out_stack.pop();
  }
}
