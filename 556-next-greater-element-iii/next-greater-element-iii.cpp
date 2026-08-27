class Solution {
public:
    int nextGreaterElement(int no) {
        string s = to_string(no);
        int n = s.size();
        int i = n - 2;
        while (i >= 0 && s[i] >= s[i + 1]) i--;   // find pivot from the right
        if (i < 0) return -1;
        int j = n - 1;
        while (s[j] <= s[i]) j--;                  // rightmost digit greater than pivot
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());        // smallest suffix
        long ans = stol(s);
        return ans > INT_MAX ? -1 : (int)ans;
    }
};