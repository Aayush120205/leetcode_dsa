#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0088-merge-sorted-array/0088-merge-sorted-array.cpp"
}  // namespace
TEST(MergeSortedArray, interleaved) {
    Solution s;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    vector<int> expected{1, 2, 2, 3, 5, 6};
    CHECK_EQ(nums1, expected);
}

TEST(MergeSortedArray, second_array_empty) {
    Solution s;
    vector<int> nums1{1};
    vector<int> nums2{};
    s.merge(nums1, 1, nums2, 0);
    vector<int> expected{1};
    CHECK_EQ(nums1, expected);
}

TEST(MergeSortedArray, first_array_empty) {
    Solution s;
    vector<int> nums1{0};
    vector<int> nums2{1};
    s.merge(nums1, 0, nums2, 1);
    vector<int> expected{1};
    CHECK_EQ(nums1, expected);
}

TEST(MergeSortedArray, second_array_entirely_smaller) {
    Solution s;
    vector<int> nums1{4, 5, 6, 0, 0, 0};
    vector<int> nums2{1, 2, 3};
    s.merge(nums1, 3, nums2, 3);
    vector<int> expected{1, 2, 3, 4, 5, 6};
    CHECK_EQ(nums1, expected);
}
