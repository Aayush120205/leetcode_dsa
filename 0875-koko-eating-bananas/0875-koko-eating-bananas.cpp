#include "../utils/array_utils.hpp"
#include "../utils/binary_search.hpp"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());

        return (int)dsa::firstTrue(1, high, [&](long long hourly) {
            return dsa::sumOfCeilDiv(piles, hourly) <= h;
        });
    }
};
