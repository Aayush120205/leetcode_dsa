#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0035-search-insert-position/0035-search-insert-position.cpp"
}  // namespace
TEST(SearchInsertPosition, target_present) {
    Solution s;
    vector<int> nums{1, 3, 5, 6};
    CHECK_EQ(s.searchInsert(nums, 5), 2);
}

TEST(SearchInsertPosition, insert_in_middle) {
    Solution s;
    vector<int> nums{1, 3, 5, 6};
    CHECK_EQ(s.searchInsert(nums, 2), 1);
}

TEST(SearchInsertPosition, insert_at_end) {
    Solution s;
    vector<int> nums{1, 3, 5, 6};
    CHECK_EQ(s.searchInsert(nums, 7), 4);
}

TEST(SearchInsertPosition, insert_at_front) {
    Solution s;
    vector<int> nums{1, 3, 5, 6};
    CHECK_EQ(s.searchInsert(nums, 0), 0);
}

TEST(SearchInsertPosition, empty_array) {
    Solution s;
    vector<int> nums{};
    CHECK_EQ(s.searchInsert(nums, 4), 0);
}
