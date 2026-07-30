#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0229-majority-element-ii/0229-majority-element-ii.cpp"
}  // namespace
TEST(MajorityElementII, two_majority_elements) {
    Solution s;
    vector<int> nums{1, 2, 1, 2, 3};
    vector<int> expected{1, 2};
    CHECK_EQ(s.majorityElement(nums), expected);
}

TEST(MajorityElementII, single_majority_element) {
    Solution s;
    vector<int> nums{3, 2, 3};
    vector<int> expected{3};
    CHECK_EQ(s.majorityElement(nums), expected);
}

TEST(MajorityElementII, no_majority_element) {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5, 6};
    CHECK_TRUE(s.majorityElement(nums).empty());
}

TEST(MajorityElementII, single_element) {
    Solution s;
    vector<int> nums{1};
    vector<int> expected{1};
    CHECK_EQ(s.majorityElement(nums), expected);
}

TEST(MajorityElementII, all_equal) {
    Solution s;
    vector<int> nums{4, 4, 4, 4};
    vector<int> expected{4};
    CHECK_EQ(s.majorityElement(nums), expected);
}
