#include "../utils/binary_search.hpp"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = dsa::lowerBound(nums, target);
        if (lb == (int)nums.size() || nums[lb] != target)
            return {-1, -1};

        return {lb, dsa::upperBound(nums, target) - 1};
    }
};
