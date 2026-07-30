#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0410-split-array-largest-sum/0410-split-array-largest-sum.cpp"
}  // namespace
TEST(SplitArrayLargestSum, example) {
    Solution s;
    vector<int> nums{7, 2, 5, 10, 8};
    CHECK_EQ(s.splitArray(nums, 2), 18);
}

TEST(SplitArrayLargestSum, one_partition_is_total_sum) {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    CHECK_EQ(s.splitArray(nums, 1), 15);
}

TEST(SplitArrayLargestSum, partitions_equal_to_length) {
    Solution s;
    vector<int> nums{1, 4, 4};
    CHECK_EQ(s.splitArray(nums, 3), 4);
}

TEST(SplitArrayLargestSum, single_element) {
    Solution s;
    vector<int> nums{5};
    CHECK_EQ(s.splitArray(nums, 1), 5);
}

TEST(SplitArrayLargestSum, count_partitions_helper) {
    Solution s;
    vector<int> nums{7, 2, 5, 10, 8};
    CHECK_EQ(s.countPartitions(nums, 18), 2);
    CHECK_EQ(s.countPartitions(nums, 10), 4);
}
