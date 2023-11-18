#include "gtest/gtest.h"
#include "../src/add_function.hpp"

TEST(AddTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_EQ(add(1, 1), 2);
  EXPECT_EQ(add(2, 2), 4);
  // Expect equality.
  EXPECT_EQ(add(5, -5), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
