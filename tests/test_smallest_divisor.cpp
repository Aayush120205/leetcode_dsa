#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../1283-find-the-smallest-divisor-given-a-threshold/1283-find-the-smallest-divisor-given-a-threshold.cpp"
}  // namespace
TEST(SmallestDivisor, example) {
    Solution s;
    vector<int> nums{1, 2, 5, 9};
    CHECK_EQ(s.smallestDivisor(nums, 6), 5);
}

TEST(SmallestDivisor, larger_threshold_allows_larger_divisor) {
    Solution s;
    vector<int> nums{1, 2, 5, 9};
    CHECK_EQ(s.smallestDivisor(nums, 17), 1);
}

TEST(SmallestDivisor, threshold_equals_length_forces_max) {
    Solution s;
    vector<int> nums{44, 22, 33, 11, 1};
    CHECK_EQ(s.smallestDivisor(nums, 5), 44);
}

TEST(SmallestDivisor, single_element) {
    Solution s;
    vector<int> nums{19};
    CHECK_EQ(s.smallestDivisor(nums, 5), 4);
}

TEST(SmallestDivisor, sum_by_divisor_helper_rounds_up) {
    Solution s;
    vector<int> nums{1, 2, 5, 9};
    CHECK_EQ(s.sumbyD(nums, 5), 5);
    CHECK_EQ(s.sumbyD(nums, 1), 17);
}
