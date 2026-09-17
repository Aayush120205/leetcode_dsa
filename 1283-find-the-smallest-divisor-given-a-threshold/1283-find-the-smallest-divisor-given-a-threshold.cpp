#include "../utils/array_utils.hpp"
#include "../utils/binary_search.hpp"

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = *max_element(nums.begin(), nums.end());

        return (int)dsa::firstTrue(1, high, [&](long long div) {
            return dsa::sumOfCeilDiv(nums, div) <= threshold;
        });
    }
};
