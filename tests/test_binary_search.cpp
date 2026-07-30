#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0704-binary-search/0704-binary-search.cpp"
}  // namespace
TEST(BinarySearch, target_present) {
    Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    CHECK_EQ(s.search(nums, 9), 4);
}

TEST(BinarySearch, target_absent) {
    Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    CHECK_EQ(s.search(nums, 2), -1);
}

TEST(BinarySearch, first_element) {
    Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    CHECK_EQ(s.search(nums, -1), 0);
}

TEST(BinarySearch, last_element) {
    Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    CHECK_EQ(s.search(nums, 12), 5);
}

TEST(BinarySearch, empty_array) {
    Solution s;
    vector<int> nums{};
    CHECK_EQ(s.search(nums, 1), -1);
}
