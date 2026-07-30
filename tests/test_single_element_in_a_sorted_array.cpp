#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0540-single-element-in-a-sorted-array/0540-single-element-in-a-sorted-array.cpp"
}  // namespace
TEST(SingleElementInASortedArray, single_in_middle) {
    Solution s;
    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
    CHECK_EQ(s.singleNonDuplicate(nums), 2);
}

TEST(SingleElementInASortedArray, single_near_end) {
    Solution s;
    vector<int> nums{3, 3, 7, 7, 10, 11, 11};
    CHECK_EQ(s.singleNonDuplicate(nums), 10);
}

TEST(SingleElementInASortedArray, only_element) {
    Solution s;
    vector<int> nums{1};
    CHECK_EQ(s.singleNonDuplicate(nums), 1);
}

TEST(SingleElementInASortedArray, single_at_front) {
    Solution s;
    vector<int> nums{1, 2, 2, 3, 3};
    CHECK_EQ(s.singleNonDuplicate(nums), 1);
}

TEST(SingleElementInASortedArray, single_at_back) {
    Solution s;
    vector<int> nums{1, 1, 2, 2, 3};
    CHECK_EQ(s.singleNonDuplicate(nums), 3);
}
