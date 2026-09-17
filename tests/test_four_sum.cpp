#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0018-4sum/0018-4sum.cpp"
}  // namespace
TEST(FourSum, example) {
    Solution s;
    vector<int> nums{1, 0, -1, 0, -2, 2};
    vector<vector<int>> expected{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    CHECK_EQ(s.fourSum(nums, 0), expected);
}

TEST(FourSum, repeated_values) {
    Solution s;
    vector<int> nums{2, 2, 2, 2, 2};
    vector<vector<int>> expected{{2, 2, 2, 2}};
    CHECK_EQ(s.fourSum(nums, 8), expected);
}

TEST(FourSum, no_quadruplet) {
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    CHECK_TRUE(s.fourSum(nums, 100).empty());
}

TEST(FourSum, overflow_safe_for_extreme_values) {
    Solution s;
    vector<int> nums{1000000000, 1000000000, 1000000000, 1000000000};
    CHECK_TRUE(s.fourSum(nums, -294967296).empty());
}
