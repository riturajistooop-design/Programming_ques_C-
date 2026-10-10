class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<long long> pq;
        for (int i = 0; i < (int)nums1.size(); i++)
            pq.push(abs(nums1[i] - nums2[i]));

        long long total = (long long)k1 + k2;
        long long ans = 0, count = 0, cur = pq.top();

        while (total > 0 && cur > 0) {
            // absorb every element currently at level `cur`
            while (!pq.empty() && pq.top() == cur) {
                pq.pop();
                count++;
            }
            long long next = pq.empty() ? 0 : pq.top();
            long long need = count * (cur - next);

            if (total >= need) {          // can level the whole group down to `next`
                total -= need;
                cur = next;
            } else {                      // partial: can't reach `next`
                long long dec = total / count;
                long long rem = total % count;
                cur -= dec;
                // rem elements go one lower, the rest stay at cur
                ans += rem * (cur - 1) * (cur - 1);
                ans += (count - rem) * cur * cur;
                count = 0;                // group already accounted for
                total = 0;
            }
        }

        ans += count * cur * cur;         // group (if not already added)
        while (!pq.empty()) {             // untouched smaller elements
            long long t = pq.top(); pq.pop();
            ans += t * t;
        }
        return ans;
    }
};