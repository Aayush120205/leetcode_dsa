#pragma once

#include "leetcode.hpp"

namespace dsa {

// Smallest x in [low, high] with pred(x) == true, assuming pred is monotonic
// (false...false, true...true). Returns high + 1 when pred is never true.
template <class Pred>
long long firstTrue(long long low, long long high, Pred pred) {
    long long ans = high + 1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (pred(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Largest x in [low, high] with pred(x) == true, assuming pred is monotonic
// (true...true, false...false). Returns low - 1 when pred is never true.
template <class Pred>
long long lastTrue(long long low, long long high, Pred pred) {
    long long ans = low - 1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (pred(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// First index whose value is >= target, or nums.size() when there is none.
inline int lowerBound(const vector<int>& nums, int target) {
    return (int)firstTrue(0, (long long)nums.size() - 1,
                          [&](long long i) { return nums[i] >= target; });
}

// First index whose value is > target, or nums.size() when there is none.
inline int upperBound(const vector<int>& nums, int target) {
    return (int)firstTrue(0, (long long)nums.size() - 1,
                          [&](long long i) { return nums[i] > target; });
}

// Index of target in a sorted array, or -1 when absent.
inline int binarySearch(const vector<int>& nums, int target) {
    int i = lowerBound(nums, target);
    if (i == (int)nums.size() || nums[i] != target) return -1;
    return i;
}

}  // namespace dsa
