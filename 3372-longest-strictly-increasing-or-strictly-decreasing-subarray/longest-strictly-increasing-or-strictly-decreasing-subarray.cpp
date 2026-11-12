class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int ans = 1, curr = 1, flag = 0;
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) {
                curr = (flag == 1) ? curr + 1 : 2;
                flag = 1;
            } else if (arr[i] < arr[i-1]) {
                curr = (flag == -1) ? curr + 1 : 2;
                flag = -1;
            } else {
                curr = 1;
                flag = 0;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};