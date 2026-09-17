class Solution {
public:
    int findDays(vector<int> &weights, int cap) {
        int days = 1, load = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        if (weights.empty()) return 0;

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int numofdays = findDays(weights, mid);

            if (numofdays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};