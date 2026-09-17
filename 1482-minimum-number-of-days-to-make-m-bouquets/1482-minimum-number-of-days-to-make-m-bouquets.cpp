#include "../utils/binary_search.hpp"

class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int bouquets = 0;

        for (int i = 0; i < (int)bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > (long long)bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        return (int)dsa::firstTrue(low, high, [&](long long day) {
            return possible(bloomDay, (int)day, m, k);
        });
    }
};
