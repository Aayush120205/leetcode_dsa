#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../1011-capacity-to-ship-packages-within-d-days/1011-capacity-to-ship-packages-within-d-days.cpp"
}  // namespace
TEST(CapacityToShipPackages, example) {
    Solution s;
    vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CHECK_EQ(s.shipWithinDays(weights, 5), 15);
}

TEST(CapacityToShipPackages, one_day_needs_full_sum) {
    Solution s;
    vector<int> weights{3, 2, 2, 4, 1, 4};
    CHECK_EQ(s.shipWithinDays(weights, 1), 16);
}

TEST(CapacityToShipPackages, days_equal_to_package_count) {
    Solution s;
    vector<int> weights{1, 2, 3, 1, 1};
    CHECK_EQ(s.shipWithinDays(weights, 4), 3);
}

TEST(CapacityToShipPackages, single_package) {
    Solution s;
    vector<int> weights{7};
    CHECK_EQ(s.shipWithinDays(weights, 1), 7);
}

TEST(CapacityToShipPackages, find_days_helper) {
    Solution s;
    vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CHECK_EQ(s.findDays(weights, 15), 5);
    CHECK_EQ(s.findDays(weights, 55), 1);
}
