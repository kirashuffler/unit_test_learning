#include "gtest/gtest.h"
#include "../include/solve.hpp"

TEST(QuadraticEquationSolve, Case1) {
  SCOPED_TRACE("x^2+1 = 0 - should have no roots");
  auto res = solve(1,0,1);
  EXPECT_EQ(res.size(), 0);
}

TEST(QuadraticEquationSolve, Case2) {
  SCOPED_TRACE("x^2-1 = 0 - multiplicity of roots should be 1");
  auto res = solve(1,0,-1);
  EXPECT_EQ(res.size(), 2);
}

TEST(QuadraticEquationSolve, Case3) {
  SCOPED_TRACE("x^2+2x+1 = 0 - one root with multiplicity of 2");
  auto res = solve(1,2,1);
  EXPECT_EQ(res.size(), 1);
}

TEST(QuadraticEquationSolve, Case4) {
  SCOPED_TRACE("a == 0 - should throw an exception");
  EXPECT_THROW({solve(0,2,1);}, std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
