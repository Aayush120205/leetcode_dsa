#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0493-reverse-pairs/0493-reverse-pairs.cpp"
}  // namespace
TEST(ReversePairs, example_one) {
    Solution s;
    vector<int> nums{1, 3, 2, 3, 1};
    CHECK_EQ(s.reversePairs(nums), 2);
}

TEST(ReversePairs, example_two) {
    Solution s;
    vector<int> nums{2, 4, 3, 5, 1};
    CHECK_EQ(s.reversePairs(nums), 3);
}

TEST(ReversePairs, no_pairs) {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    CHECK_EQ(s.reversePairs(nums), 0);
}

TEST(ReversePairs, single_element) {
    Solution s;
    vector<int> nums{1};
    CHECK_EQ(s.reversePairs(nums), 0);
}

TEST(ReversePairs, extreme_values_do_not_overflow) {
    Solution s;
    vector<int> nums{2147483647, 2147483647, -2147483648, -2147483648};
    CHECK_EQ(s.reversePairs(nums), 5);
}

TEST(ReversePairs, input_is_sorted_as_a_side_effect) {
    Solution s;
    vector<int> nums{5, 4, 3, 2, 1};
    s.reversePairs(nums);
    vector<int> expected{1, 2, 3, 4, 5};
    CHECK_EQ(nums, expected);
}
