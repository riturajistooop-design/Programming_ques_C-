class Solution {
public:
    string convert(string& s, int& k) {
        int n = s.length();
        int count = 0;
        string ans = "";
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i] - '0';
            count++;
            if (count == k) {
                ans += to_string(sum);
                sum = 0;
                count = 0;
            }
        }
        if (count > 0) ans += to_string(sum);
        return ans;
    }
    string digitSum(string s, int k) {
        while (s.length() > k) {
            s = convert(s, k);
        }
        return s;
    }
};