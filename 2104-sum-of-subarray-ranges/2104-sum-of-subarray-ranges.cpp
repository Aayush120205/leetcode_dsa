class Solution {
public:

    // Sum of Subarray Minimums
    long long subarrayMin(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long sum = 0;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                  (i == n || arr[st.top()] >= arr[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

                sum += (long long)arr[mid] * left * right;
            }

            st.push(i);
        }

        return sum;
    }

    // Sum of Subarray Maximums
    long long subarrayMax(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long sum = 0;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                  (i == n || arr[st.top()] <= arr[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

                sum += (long long)arr[mid] * left * right;
            }

            st.push(i);
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long smallest = subarrayMin(nums);
        long long largest = subarrayMax(nums);

        return largest - smallest;
    }
};