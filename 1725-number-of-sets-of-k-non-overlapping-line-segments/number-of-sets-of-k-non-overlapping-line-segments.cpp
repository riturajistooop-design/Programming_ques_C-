#define MOD 1000000007
class Solution {
public:
    vector<vector<long long>> dp;   // dp[idx][count]
    vector<vector<long long>> suf;  // suf[idx][count] = sum of f(t, count) for t = idx..n-1

    long long g(int n, int idx, int count) {
        if (idx >= n) return 0;
        if (suf[idx][count] != -1) return suf[idx][count];
        long long res = (f(n, idx, count) + g(n, idx + 1, count)) % MOD;
        return suf[idx][count] = res;
    }

    long long f(int n, int idx, int count) {
        if (count == 0) return 1;
        if (idx >= n) return 0;
        if (dp[idx][count] != -1) return dp[idx][count];
        // this replaces the old "for(len=1..) res += f(idx+len, count-1)" loop:
        long long res = (f(n, idx + 1, count) + g(n, idx + 1, count - 1)) % MOD;
        return dp[idx][count] = res;
    }

    int numberOfSets(int n, int k) {
        dp.assign(n + 1, vector<long long>(k + 1, -1));
        suf.assign(n + 1, vector<long long>(k + 1, -1));
        return (int)f(n, 0, k);
    }
};