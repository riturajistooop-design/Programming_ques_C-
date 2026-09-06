class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        unordered_map<char, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[t[i]].push_back(i);
        }
        vector<unsigned long long> dp(n, 0);   // must be long long, not int
        int i = m - 1;
        while (i >= 0) {
            int sz = (map[s[i]]).size();
            for (int k = 0; k < sz; k++) {
                int idx = map[s[i]][k];
                if (idx == n - 1) dp[n - 1]++;
                else dp[idx] += dp[idx + 1];
            }
            i--;
        }
        return (int)dp[0];
    }
};