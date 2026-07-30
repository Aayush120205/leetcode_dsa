#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0015-3sum/0015-3sum.cpp"
}  // namespace
TEST(ThreeSum, example_with_duplicates) {
    Solution s;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> expected{{-1, -1, 2}, {-1, 0, 1}};
    CHECK_EQ(s.threeSum(nums), expected);
}

TEST(ThreeSum, no_triplet) {
    Solution s;
    vector<int> nums{0, 1, 1};
    CHECK_TRUE(s.threeSum(nums).empty());
}

TEST(ThreeSum, all_zeros_deduplicated) {
    Solution s;
    vector<int> nums{0, 0, 0, 0};
    vector<vector<int>> expected{{0, 0, 0}};
    CHECK_EQ(s.threeSum(nums), expected);
}

TEST(ThreeSum, fewer_than_three_elements) {
    Solution s;
    vector<int> nums{1, -1};
    CHECK_TRUE(s.threeSum(nums).empty());
}
