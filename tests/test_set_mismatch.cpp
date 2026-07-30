#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0645-set-mismatch/0645-set-mismatch.cpp"
}  // namespace
TEST(SetMismatch, example) {
    Solution s;
    vector<int> nums{1, 2, 2, 4};
    vector<int> expected{2, 3};
    CHECK_EQ(s.findErrorNums(nums), expected);
}

TEST(SetMismatch, duplicate_of_first_number) {
    Solution s;
    vector<int> nums{1, 1};
    vector<int> expected{1, 2};
    CHECK_EQ(s.findErrorNums(nums), expected);
}

TEST(SetMismatch, duplicate_at_end) {
    Solution s;
    vector<int> nums{2, 3, 3};
    vector<int> expected{3, 1};
    CHECK_EQ(s.findErrorNums(nums), expected);
}

TEST(SetMismatch, longer_array) {
    Solution s;
    vector<int> nums{3, 2, 3, 4, 6, 5};
    vector<int> expected{3, 1};
    CHECK_EQ(s.findErrorNums(nums), expected);
}
