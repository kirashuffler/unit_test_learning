#include "gtest/gtest.h"
#include "../include/solve.hpp"

TEST(SolveTest, BasicAssertions) {
  auto res = solve(1,1,1);
  EXPECT_EQ(res.size(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
