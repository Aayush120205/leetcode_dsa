#include "../utils/array_utils.hpp"
#include "../utils/binary_search.hpp"

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL);

        return (int)dsa::firstTrue(low, high, [&](long long capacity) {
            return dsa::countGroupsWithCapacity(weights, capacity) <= days;
        });
    }
};
