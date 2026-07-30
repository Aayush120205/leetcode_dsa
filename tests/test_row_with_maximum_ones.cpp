#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../2643-row-with-maximum-ones/2643-row-with-maximum-ones.cpp"
}  // namespace
TEST(RowWithMaximumOnes, second_row_wins) {
    Solution s;
    vector<vector<int>> mat{{0, 1}, {1, 0}};
    vector<int> expected{0, 1};
    CHECK_EQ(s.rowAndMaximumOnes(mat), expected);
}

TEST(RowWithMaximumOnes, ties_pick_lowest_index) {
    Solution s;
    vector<vector<int>> mat{{0, 0, 0}, {0, 1, 1}, {1, 1, 0}};
    vector<int> expected{1, 2};
    CHECK_EQ(s.rowAndMaximumOnes(mat), expected);
}

TEST(RowWithMaximumOnes, all_zeros) {
    Solution s;
    vector<vector<int>> mat{{0, 0}, {0, 0}};
    vector<int> expected{0, 0};
    CHECK_EQ(s.rowAndMaximumOnes(mat), expected);
}

TEST(RowWithMaximumOnes, single_row) {
    Solution s;
    vector<vector<int>> mat{{1, 1, 1}};
    vector<int> expected{0, 3};
    CHECK_EQ(s.rowAndMaximumOnes(mat), expected);
}
