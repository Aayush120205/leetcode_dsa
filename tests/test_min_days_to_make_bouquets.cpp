#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../1482-minimum-number-of-days-to-make-m-bouquets/1482-minimum-number-of-days-to-make-m-bouquets.cpp"
}  // namespace
TEST(MinDaysToMakeBouquets, impossible_request) {
    Solution s;
    vector<int> bloomDay{1, 10, 3, 10, 2};
    CHECK_EQ(s.minDays(bloomDay, 3, 3), -1);
}

TEST(MinDaysToMakeBouquets, adjacent_flowers_required) {
    Solution s;
    vector<int> bloomDay{1, 10, 3, 10, 2};
    CHECK_EQ(s.minDays(bloomDay, 3, 1), 3);
}

TEST(MinDaysToMakeBouquets, groups_of_two) {
    Solution s;
    vector<int> bloomDay{7, 7, 7, 7, 12, 7, 7};
    CHECK_EQ(s.minDays(bloomDay, 2, 3), 12);
}

TEST(MinDaysToMakeBouquets, single_flower) {
    Solution s;
    vector<int> bloomDay{5};
    CHECK_EQ(s.minDays(bloomDay, 1, 1), 5);
}

TEST(MinDaysToMakeBouquets, possible_helper) {
    Solution s;
    vector<int> bloomDay{1, 10, 3, 10, 2};
    CHECK_TRUE(s.possible(bloomDay, 3, 3, 1));
    CHECK_TRUE(!s.possible(bloomDay, 2, 3, 1));
}
