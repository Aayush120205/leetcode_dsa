#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0069-sqrtx/0069-sqrtx.cpp"
}  // namespace
TEST(Sqrtx, perfect_square) {
    Solution s;
    CHECK_EQ(s.mySqrt(4), 2);
}

TEST(Sqrtx, truncates_towards_zero) {
    Solution s;
    CHECK_EQ(s.mySqrt(8), 2);
}

TEST(Sqrtx, zero) {
    Solution s;
    CHECK_EQ(s.mySqrt(0), 0);
}

TEST(Sqrtx, one) {
    Solution s;
    CHECK_EQ(s.mySqrt(1), 1);
}

TEST(Sqrtx, large_input_does_not_overflow) {
    Solution s;
    CHECK_EQ(s.mySqrt(2147395599), 46339);
    CHECK_EQ(s.mySqrt(2147483647), 46340);
}
