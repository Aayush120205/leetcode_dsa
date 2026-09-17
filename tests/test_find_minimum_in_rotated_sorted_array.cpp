#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0153-find-minimum-in-rotated-sorted-array/0153-find-minimum-in-rotated-sorted-array.cpp"
}  // namespace
TEST(FindMinimumInRotatedSortedArray, rotated) {
    Solution s;
    vector<int> nums{3, 4, 5, 1, 2};
    CHECK_EQ(s.findMin(nums), 1);
}

TEST(FindMinimumInRotatedSortedArray, rotated_at_last_element) {
    Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    CHECK_EQ(s.findMin(nums), 0);
}

TEST(FindMinimumInRotatedSortedArray, minimum_left_of_midpoint) {
    Solution s;
    vector<int> nums{6, 7, 0, 1, 2, 4, 5};
    CHECK_EQ(s.findMin(nums), 0);
}

TEST(FindMinimumInRotatedSortedArray, not_rotated) {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    CHECK_EQ(s.findMin(nums), 1);
}

TEST(FindMinimumInRotatedSortedArray, single_element) {
    Solution s;
    vector<int> nums{7};
    CHECK_EQ(s.findMin(nums), 7);
}

TEST(FindMinimumInRotatedSortedArray, negative_values) {
    Solution s;
    vector<int> nums{2, 3, -5, -1};
    CHECK_EQ(s.findMin(nums), -5);
}
