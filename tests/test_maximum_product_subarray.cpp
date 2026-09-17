#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0152-maximum-product-subarray/0152-maximum-product-subarray.cpp"
}  // namespace
TEST(MaximumProductSubarray, example_with_negative) {
    Solution s;
    vector<int> nums{2, 3, -2, 4};
    CHECK_EQ(s.maxProduct(nums), 6);
}

TEST(MaximumProductSubarray, zero_resets_running_product) {
    Solution s;
    vector<int> nums{-2, 0, -1};
    CHECK_EQ(s.maxProduct(nums), 0);
}

TEST(MaximumProductSubarray, two_negatives_multiply_positive) {
    Solution s;
    vector<int> nums{-2, 3, -4};
    CHECK_EQ(s.maxProduct(nums), 24);
}

TEST(MaximumProductSubarray, single_negative_element) {
    Solution s;
    vector<int> nums{-3};
    CHECK_EQ(s.maxProduct(nums), -3);
}

TEST(MaximumProductSubarray, all_positive) {
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    CHECK_EQ(s.maxProduct(nums), 24);
}
