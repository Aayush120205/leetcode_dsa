#include "../utils/array_utils.hpp"
#include "../utils/binary_search.hpp"

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        return (int)dsa::firstTrue(low, high, [&](long long maxSum) {
            return dsa::countGroupsWithCapacity(nums, maxSum) <= k;
        });
    }
};
