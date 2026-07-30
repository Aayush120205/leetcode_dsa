class Solution {
public:
    long long findTotalHours(vector<int> &piles, int hourly) {
        long long totalH = 0;
        for (int pile : piles) {
            totalH += (pile + hourly - 1) / hourly;
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.empty()) return 0;

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (findTotalHours(piles, mid) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};