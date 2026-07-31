class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;

        sort(freq.rbegin(), freq.rend()); // descending

        int total = 0;
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            int presses = i / 8 + 1;   // 1st 8 letters cost 1, next 8 cost 2, etc.
            total += presses * freq[i];
        }
        return total;
    }
};