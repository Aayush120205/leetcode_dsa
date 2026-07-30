#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0875-koko-eating-bananas/0875-koko-eating-bananas.cpp"
}  // namespace
TEST(KokoEatingBananas, example) {
    Solution s;
    vector<int> piles{3, 6, 7, 11};
    CHECK_EQ(s.minEatingSpeed(piles, 8), 4);
}

TEST(KokoEatingBananas, tight_deadline) {
    Solution s;
    vector<int> piles{30, 11, 23, 4, 20};
    CHECK_EQ(s.minEatingSpeed(piles, 5), 30);
}

TEST(KokoEatingBananas, relaxed_deadline) {
    Solution s;
    vector<int> piles{30, 11, 23, 4, 20};
    CHECK_EQ(s.minEatingSpeed(piles, 6), 23);
}

TEST(KokoEatingBananas, single_pile) {
    Solution s;
    vector<int> piles{1000000000};
    CHECK_EQ(s.minEatingSpeed(piles, 2), 500000000);
}

TEST(KokoEatingBananas, total_hours_helper_rounds_up) {
    Solution s;
    vector<int> piles{3, 6, 7, 11};
    CHECK_EQ(s.findTotalHours(piles, 4), 8LL);
    CHECK_EQ(s.findTotalHours(piles, 3), 10LL);
}
