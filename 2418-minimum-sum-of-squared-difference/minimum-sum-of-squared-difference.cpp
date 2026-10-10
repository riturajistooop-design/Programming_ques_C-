class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int MAXD = 100000;
        vector<long long> cnt(MAXD + 1, 0);
        long long k = (long long)k1 + k2, sum = 0;

        for (int i = 0; i < (int)nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            sum += d;
        }
        if (sum <= k) return 0;                 // everything can reach 0

        long long group = 0;                    // elements currently at level d
        for (int d = MAXD; d >= 1; d--) {
            group += cnt[d];
            if (group == 0) continue;

            if (k >= group) {                   // lower whole group to d-1
                k -= group;
            } else {                            // partial: k elements drop to d-1
                long long ans = k * (d - 1) * (d - 1)
                              + (group - k) * d * d;
                for (long long j = 1; j < d; j++)   // untouched smaller values
                    ans += cnt[j] * j * j;
                return ans;
            }
        }
        return 0;                               // unreachable given sum > k
    }
};