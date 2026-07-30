#pragma once

#include "leetcode.hpp"

namespace dsa {

// True when nums[i] repeats the previous value inside the window starting at
// `start`, i.e. when a k-sum loop should skip index i to avoid duplicates.
inline bool isDuplicateAt(const vector<int>& nums, int i, int start) {
    return i > start && nums[i] == nums[i - 1];
}

// All value pairs in the sorted range nums[lo..hi] summing to target, without
// duplicate pairs. Used as the innermost step of the k-sum family.
inline vector<pair<int, int>> twoSumPairs(const vector<int>& nums, int lo,
                                         int hi, long long target) {
    vector<pair<int, int>> pairs;
    while (lo < hi) {
        long long sum = (long long)nums[lo] + nums[hi];
        if (sum < target) {
            lo++;
        } else if (sum > target) {
            hi--;
        } else {
            pairs.push_back({nums[lo], nums[hi]});
            lo++;
            hi--;
            while (lo < hi && nums[lo] == nums[lo - 1]) lo++;
            while (lo < hi && nums[hi] == nums[hi + 1]) hi--;
        }
    }
    return pairs;
}

}  // namespace dsa
