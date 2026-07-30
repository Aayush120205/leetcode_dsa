#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0004-median-of-two-sorted-arrays/0004-median-of-two-sorted-arrays.cpp"
}  // namespace
TEST(MedianOfTwoSortedArrays, odd_total_length) {
    Solution s;
    vector<int> a{1, 3}, b{2};
    CHECK_NEAR(s.findMedianSortedArrays(a, b), 2.0, 1e-9);
}

TEST(MedianOfTwoSortedArrays, even_total_length) {
    Solution s;
    vector<int> a{1, 2}, b{3, 4};
    CHECK_NEAR(s.findMedianSortedArrays(a, b), 2.5, 1e-9);
}

TEST(MedianOfTwoSortedArrays, first_array_empty) {
    Solution s;
    vector<int> a{}, b{2, 3, 4};
    CHECK_NEAR(s.findMedianSortedArrays(a, b), 3.0, 1e-9);
}

TEST(MedianOfTwoSortedArrays, second_array_empty) {
    Solution s;
    vector<int> a{5, 6, 7, 8}, b{};
    CHECK_NEAR(s.findMedianSortedArrays(a, b), 6.5, 1e-9);
}

TEST(MedianOfTwoSortedArrays, disjoint_ranges) {
    Solution s;
    vector<int> a{1, 2, 3}, b{100, 200};
    CHECK_NEAR(s.findMedianSortedArrays(a, b), 3.0, 1e-9);
}

TEST(MedianOfTwoSortedArrays, single_element_each) {
    Solution s;
    vector<int> a{-5}, b{5};
    CHECK_NEAR(s.findMedianSortedArrays(a, b), 0.0, 1e-9);
}
