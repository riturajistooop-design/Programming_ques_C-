class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            int pushesNeeded = i / 8 + 1; // 1st 8 letters cost 1 push, next 8 cost 2, etc.
            totalPushes += freq[i] * pushesNeeded;
        }
        return totalPushes;
    }
};