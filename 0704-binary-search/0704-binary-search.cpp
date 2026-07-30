#include "../utils/binary_search.hpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return dsa::binarySearch(nums, target);
    }
};
