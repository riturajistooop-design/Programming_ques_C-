class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;
        int n = s.size();
        vector<long long> dp(n + 1);
        dp[0] = 1; // dp[i] = total distinct subsequences (incl. empty) using s[0..i-1]
        vector<int> last(26, -1); // last[c] = index i (into dp) where dp was last updated for char c

        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            int c = s[i - 1] - 'a';
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }
            last[c] = i;
        }
        return (int)((dp[n] - 1 + MOD) % MOD); // subtract the empty subsequence
    }
};