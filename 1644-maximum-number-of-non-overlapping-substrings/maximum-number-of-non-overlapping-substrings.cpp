class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        // Immutable table of each letter's first/last occurrence.
        // NEVER modified after this point.
        vector<vector<int>> orig(26, vector<int>(2, -1));
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (orig[idx][0] == -1) orig[idx][0] = orig[idx][1] = i;
            else orig[idx][1] = i;
        }

        // Build valid, self-consistent candidate intervals into a
        // SEPARATE array, always reading from 'orig' (never from a
        // partially-updated candidate) so earlier invalidations can't
        // corrupt later checks.
        vector<vector<int>> candidates;
        for (int c = 0; c < 26; c++) {
            if (orig[c][0] == -1) continue;
            int start = orig[c][0], end = orig[c][1];
            bool valid = true;
            for (int i = start; i <= end; i++) {
                int c2 = s[i] - 'a';
                if (orig[c2][0] < start) { valid = false; break; }
                end = max(end, orig[c2][1]);
            }
            if (valid) candidates.push_back({start, end});
        }

        // Smallest intervals first, so nested valid pieces win over the
        // larger interval that contains them.
        sort(candidates.begin(), candidates.end(),
             [](vector<int>& a, vector<int>& b) {
                 return (a[1] - a[0]) < (b[1] - b[0]);
             });

        vector<int> visited(n, 0);
        vector<string> res;
        for (auto& iv : candidates) {
            bool overlap = false;
            for (int i = iv[0]; i <= iv[1]; i++) {
                if (visited[i]) { overlap = true; break; }
            }
            if (overlap) continue;
            for (int i = iv[0]; i <= iv[1]; i++) visited[i] = 1;
            res.push_back(s.substr(iv[0], iv[1] - iv[0] + 1));
        }
        return res;
    }
};