#include "../utils/two_pointers.hpp"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (dsa::isDuplicateAt(nums, i, 0)) continue;

            for (int j = i + 1; j < n; j++) {
                if (dsa::isDuplicateAt(nums, j, i + 1)) continue;

                long long rest = (long long)target - nums[i] - nums[j];
                for (auto& p : dsa::twoSumPairs(nums, j + 1, n - 1, rest)) {
                    ans.push_back({nums[i], nums[j], p.first, p.second});
                }
            }
        }

        return ans;
    }
};
