#pragma once

#include "leetcode.hpp"

namespace dsa {

// Greedily splits nums into consecutive groups whose sums stay within capacity
// and returns the number of groups. Values larger than capacity end up alone in
// a group, so the result is only meaningful for capacity >= max(nums).
inline long long countGroupsWithCapacity(const vector<int>& nums,
                                         long long capacity) {
    long long groups = 1;
    long long load = 0;
    for (int value : nums) {
        if (load + value <= capacity) {
            load += value;
        } else {
            groups++;
            load = value;
        }
    }
    return groups;
}

// Sum of ceil(value / divisor) over nums, for divisor > 0.
inline long long sumOfCeilDiv(const vector<int>& nums, long long divisor) {
    long long total = 0;
    for (int value : nums) {
        total += (value + divisor - 1) / divisor;
    }
    return total;
}

}  // namespace dsa
