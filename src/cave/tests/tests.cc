// #pragma once

#include <gtest/gtest.h>

#include "../cave.h"

using namespace s21;

class CaveTest : public testing::Test {
 public:
  void file_test(std::string test_file, int birth_limit_, int death_limit_,
                 std::string expected_file) {
    Cave *test = new Cave(test_file, birth_limit_, death_limit_);
    while (!test->Update()) {
    }
    Cave *expected = new Cave(expected_file, 0, 0);
    auto size = expected->GetSize();
    for (int i = 0; i < size.first; ++i) {
      for (int j = 0; j < size.second; ++j) {
        ASSERT_EQ(test->GetLive(i, j), expected->GetLive(i, j));
      }
    }
    delete test;
    delete expected;
  }
  void generator_test(int x, int y, double init_chance) {
    Cave *test = new Cave(x, y, init_chance, 0, 0);
    long long int square = x * y, live = 0;
    for (int i = 0; i < y; ++i) {
      for (int j = 0; j < x; ++j) {
        live += test->GetLive(i, j);
      }
    }
    ASSERT_EQ(live * 100 / square - (int)(init_chance * 100) < 5, true);
    delete test;
  }
};

TEST_F(CaveTest, test_1) {
  file_test("caves/test1.mzcv", 4, 3, "caves/expected1.mzcv");
}

TEST_F(CaveTest, test_2) {
  file_test("caves/test2.mzcv", 6, 1, "caves/expected2.mzcv");
}

TEST_F(CaveTest, test_3) {
  file_test("caves/test3.mzcv", 2, 5, "caves/expected3.mzcv");
}

TEST_F(CaveTest, generator_1) { generator_test(1000, 1000, 0.75); }

TEST_F(CaveTest, generator_2) { generator_test(4323, 357, 0.25); }

TEST_F(CaveTest, generator_3) { generator_test(12, 123, 0.37); }
