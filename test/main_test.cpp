#include "gtest/gtest.h"
#include "../include/QuadraticEquationSolve.hpp"

TEST(QuadraticEquationSolve, Case1) {
  SCOPED_TRACE("x^2+1 = 0 - should have no roots, D < 0");
  double a = 1, b = 0, c = 1;
  auto res = QuadraticEquationSolve(a, b, c);
  EXPECT_EQ(res.size(), 0);
}

TEST(QuadraticEquationSolve, Case2) {
  SCOPED_TRACE("x^2-1 = 0 - multiplicity of roots should be 1 and roots are 1 and -1");
  double a = 1, b = 0, c = -1;
  auto res = QuadraticEquationSolve(a, b, c);
  EXPECT_EQ(res.size(), 2);

  double first_expected_root = 1;
  bool is_equal_to_first_root = (res[0] < first_expected_root + e) && (res[0] > first_expected_root - e);
  EXPECT_EQ(is_equal_to_first_root, true);

  double second_expected_root = -1;
  bool is_equal_to_second_root = (res[1] < second_expected_root + e) && (res[1] > second_expected_root - e);
  EXPECT_EQ(is_equal_to_second_root, true);
}

TEST(QuadraticEquationSolve, Case3) {
  SCOPED_TRACE("x^1+1+c = 0, where c is some value less than epsilon - one root with multiplicity of 2, D == 0");
  double a = 1, b = 1, c = (1 + 10e-10 - e)/4;
  auto res = QuadraticEquationSolve(a, b, c);
  EXPECT_EQ(res.size(), 1);

  double expected_root = -0.5;
  bool is_equal_to_expected = (res[0] < expected_root + e) && (res[0] > expected_root - e);
  EXPECT_EQ(is_equal_to_expected, true);
}

TEST(QuadraticEquationSolve, Case4) {
  SCOPED_TRACE("a == 0 - should throw an exception");
  double a = 0, b = 2, c = 1;
  EXPECT_THROW({QuadraticEquationSolve(a, b, c);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case5) {
  SCOPED_TRACE("a == INF - should throw an exception");
  double a = kInfinity, b = 2, c = 1;
  EXPECT_THROW({QuadraticEquationSolve(a, b, c);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case6) {
  SCOPED_TRACE("b == INF - should throw an exception");
  double a = 1, b = kInfinity, c = 1;
  EXPECT_THROW({QuadraticEquationSolve(a, b, c);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case7) {
  SCOPED_TRACE("c == INF - should throw an exception");
  double a = 1, b = 1, c = kInfinity;
  EXPECT_THROW({QuadraticEquationSolve(a, b, c);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case8) {
  SCOPED_TRACE("a == NAN - should throw an exception");
  double a = kNan, b = 2, c = 1;
  EXPECT_THROW({QuadraticEquationSolve(a, b, c);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case9) {
  SCOPED_TRACE("b == NAN - should throw an exception");
  double a = 1, b = kNan, c = 1;
  EXPECT_THROW({QuadraticEquationSolve(a, b, c);}, std::runtime_error);
}

TEST(QuadraticEquationSolve, Case10) {
  SCOPED_TRACE("c == NAN - should throw an exception");
  double a = 1, b = 2, c = kNan;
  EXPECT_THROW({QuadraticEquationSolve(a, b, c);}, std::runtime_error);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
