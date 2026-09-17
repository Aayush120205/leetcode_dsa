#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../1004-max-consecutive-ones-iii/1004-max-consecutive-ones-iii.cpp"
}  // namespace
TEST(MaxConsecutiveOnesIII, example) {
    Solution s;
    vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    CHECK_EQ(s.longestOnes(nums, 2), 6);
}

TEST(MaxConsecutiveOnesIII, no_flips_allowed) {
    Solution s;
    vector<int> nums{1, 1, 0, 1};
    CHECK_EQ(s.longestOnes(nums, 0), 2);
}

TEST(MaxConsecutiveOnesIII, all_zeros_all_flippable) {
    Solution s;
    vector<int> nums{0, 0, 0};
    CHECK_EQ(s.longestOnes(nums, 3), 3);
}

TEST(MaxConsecutiveOnesIII, all_ones) {
    Solution s;
    vector<int> nums{1, 1, 1};
    CHECK_EQ(s.longestOnes(nums, 1), 3);
}

TEST(MaxConsecutiveOnesIII, more_flips_than_zeros) {
    Solution s;
    vector<int> nums{0, 1, 0};
    CHECK_EQ(s.longestOnes(nums, 5), 3);
}
