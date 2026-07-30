#include "../utils/two_pointers.hpp"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (dsa::isDuplicateAt(nums, i, 0)) continue;

            for (auto& p : dsa::twoSumPairs(nums, i + 1, n - 1, -(long long)nums[i])) {
                ans.push_back({nums[i], p.first, p.second});
            }
        }

        return ans;
    }
};
