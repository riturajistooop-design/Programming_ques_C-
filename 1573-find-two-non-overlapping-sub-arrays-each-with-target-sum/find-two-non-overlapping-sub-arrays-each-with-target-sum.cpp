class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i+1] = min length of a target-sum subarray within arr[0..i]
        unordered_map<long long, int> mp;
        mp[0] = -1; // prefix sum of 0 elements, "ends" before index 0

        long long sum = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            mp[sum] = i;

            dp[i + 1] = dp[i]; // carry forward best found so far

            auto it = mp.find(sum - target);
            if (it != mp.end()) {
                int start = it->second;      // subarray (start+1 .. i) sums to target
                int len = i - start;
                dp[i + 1] = min(dp[i + 1], len);

                if (dp[start + 1] != INT_MAX) {
                    ans = min(ans, dp[start + 1] + len);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};