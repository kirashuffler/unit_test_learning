#include "gtest/gtest.h"
#include "../include/QuadraticEquationSolve.hpp"

TEST(QuadraticEquationSolve, Case1) {
  SCOPED_TRACE("x^2+1 = 0 - should have no roots");
  auto res = QuadraticEquationSolve(1,0,1);
  EXPECT_EQ(res.size(), 0);
}

TEST(QuadraticEquationSolve, Case2) {
  SCOPED_TRACE("x^2-1 = 0 - multiplicity of roots should be 1");
  auto res = QuadraticEquationSolve(1,0,-1);
  EXPECT_EQ(res.size(), 2);
}

TEST(QuadraticEquationSolve, Case3) {
  SCOPED_TRACE("x^1+1+k = 0, where k is some value less than epsilon - one root with multiplicity of 2");
  const double k = (1 + 10e-10 - e)/4;
  auto res = QuadraticEquationSolve(1,1,k);
  EXPECT_EQ(res.size(), 1);
}

TEST(QuadraticEquationSolve, Case4) {
  SCOPED_TRACE("a == 0 - should throw an exception");
  EXPECT_THROW({QuadraticEquationSolve(0,2,1);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case5) {
  SCOPED_TRACE("a == INF - should throw an exception");
  EXPECT_THROW({QuadraticEquationSolve(kInfinity,2,1);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case6) {
  SCOPED_TRACE("b == INF - should throw an exception");
  EXPECT_THROW({QuadraticEquationSolve(1,kInfinity,1);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case7) {
  SCOPED_TRACE("c == INF - should throw an exception");
  EXPECT_THROW({QuadraticEquationSolve(1,2,kInfinity);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case8) {
  SCOPED_TRACE("a == NAN - should throw an exception");
  EXPECT_THROW({QuadraticEquationSolve(kNan,2,1);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case9) {
  SCOPED_TRACE("b == NAN - should throw an exception");
  EXPECT_THROW({QuadraticEquationSolve(1,kNan,1);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case10) {
  SCOPED_TRACE("c == NAN - should throw an exception");
  EXPECT_THROW({QuadraticEquationSolve(1,2,kNan);}, std::runtime_error);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
