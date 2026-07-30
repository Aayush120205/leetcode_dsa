#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp"
}  // namespace
TEST(SearchInRotatedSortedArray, target_in_right_half) {
    Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    CHECK_EQ(s.search(nums, 0), 4);
}

TEST(SearchInRotatedSortedArray, target_in_left_half) {
    Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    CHECK_EQ(s.search(nums, 5), 1);
}

TEST(SearchInRotatedSortedArray, target_absent) {
    Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    CHECK_EQ(s.search(nums, 3), -1);
}

TEST(SearchInRotatedSortedArray, single_element) {
    Solution s;
    vector<int> nums{1};
    CHECK_EQ(s.search(nums, 1), 0);
    CHECK_EQ(s.search(nums, 0), -1);
}

TEST(SearchInRotatedSortedArray, target_in_sorted_right_half) {
    Solution s;
    vector<int> nums{5, 6, 7, 0, 1, 2, 4};
    CHECK_EQ(s.search(nums, 4), 6);
    CHECK_EQ(s.search(nums, 6), 1);
    CHECK_EQ(s.search(nums, 3), -1);
}

TEST(SearchInRotatedSortedArray, not_rotated) {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    CHECK_EQ(s.search(nums, 4), 3);
}
