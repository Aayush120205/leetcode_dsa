#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0034-find-first-and-last-position-of-element-in-sorted-array/0034-find-first-and-last-position-of-element-in-sorted-array.cpp"
}  // namespace
TEST(SearchRange, target_appears_twice) {
    Solution s;
    vector<int> nums{5, 7, 7, 8, 8, 10};
    vector<int> expected{3, 4};
    CHECK_EQ(s.searchRange(nums, 8), expected);
}

TEST(SearchRange, target_missing) {
    Solution s;
    vector<int> nums{5, 7, 7, 8, 8, 10};
    vector<int> expected{-1, -1};
    CHECK_EQ(s.searchRange(nums, 6), expected);
}

TEST(SearchRange, empty_array) {
    Solution s;
    vector<int> nums{};
    vector<int> expected{-1, -1};
    CHECK_EQ(s.searchRange(nums, 0), expected);
}

TEST(SearchRange, all_elements_match) {
    Solution s;
    vector<int> nums{2, 2, 2, 2};
    vector<int> expected{0, 3};
    CHECK_EQ(s.searchRange(nums, 2), expected);
}

TEST(SearchRange, target_beyond_last_element) {
    Solution s;
    vector<int> nums{1, 2, 3};
    vector<int> expected{-1, -1};
    CHECK_EQ(s.searchRange(nums, 9), expected);
}

TEST(SearchRange, bounds_helpers) {
    Solution s;
    vector<int> nums{1, 3, 3, 5};
    CHECK_EQ(s.lowerBound(nums, 3), 1);
    CHECK_EQ(s.upperBound(nums, 3), 3);
    CHECK_EQ(s.lowerBound(nums, 6), 4);
}
