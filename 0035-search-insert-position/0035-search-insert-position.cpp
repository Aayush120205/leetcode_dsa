#include "../utils/binary_search.hpp"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return dsa::lowerBound(nums, target);
    }
};
