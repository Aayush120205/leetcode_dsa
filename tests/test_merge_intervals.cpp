#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0056-merge-intervals/0056-merge-intervals.cpp"
}  // namespace
TEST(MergeIntervals, overlapping_intervals) {
    Solution s;
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> expected{{1, 6}, {8, 10}, {15, 18}};
    CHECK_EQ(s.merge(intervals), expected);
}

TEST(MergeIntervals, touching_intervals_merge) {
    Solution s;
    vector<vector<int>> intervals{{1, 4}, {4, 5}};
    vector<vector<int>> expected{{1, 5}};
    CHECK_EQ(s.merge(intervals), expected);
}

TEST(MergeIntervals, unsorted_input) {
    Solution s;
    vector<vector<int>> intervals{{5, 6}, {1, 2}, {3, 4}};
    vector<vector<int>> expected{{1, 2}, {3, 4}, {5, 6}};
    CHECK_EQ(s.merge(intervals), expected);
}

TEST(MergeIntervals, fully_contained_interval) {
    Solution s;
    vector<vector<int>> intervals{{1, 10}, {2, 3}};
    vector<vector<int>> expected{{1, 10}};
    CHECK_EQ(s.merge(intervals), expected);
}

TEST(MergeIntervals, single_interval) {
    Solution s;
    vector<vector<int>> intervals{{1, 1}};
    vector<vector<int>> expected{{1, 1}};
    CHECK_EQ(s.merge(intervals), expected);
}
