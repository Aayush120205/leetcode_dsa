#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0162-find-peak-element/0162-find-peak-element.cpp"
}  // namespace
static bool isPeak(const vector<int>& nums, int index) {
    if (index < 0 || index >= static_cast<int>(nums.size())) return false;
    bool leftOk = index == 0 || nums[index - 1] < nums[index];
    bool rightOk = index + 1 == static_cast<int>(nums.size()) ||
                   nums[index + 1] < nums[index];
    return leftOk && rightOk;
}

TEST(FindPeakElement, single_peak) {
    Solution s;
    vector<int> nums{1, 2, 3, 1};
    CHECK_EQ(s.findPeakElement(nums), 2);
}

TEST(FindPeakElement, single_element) {
    Solution s;
    vector<int> nums{1};
    CHECK_EQ(s.findPeakElement(nums), 0);
}

TEST(FindPeakElement, peak_at_first_index) {
    Solution s;
    vector<int> nums{5, 4, 3, 2};
    CHECK_EQ(s.findPeakElement(nums), 0);
}

TEST(FindPeakElement, peak_at_last_index) {
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    CHECK_EQ(s.findPeakElement(nums), 3);
}

TEST(FindPeakElement, any_returned_index_is_a_peak) {
    Solution s;
    vector<int> nums{1, 2, 1, 3, 5, 6, 4};
    CHECK_TRUE(isPeak(nums, s.findPeakElement(nums)));
}
