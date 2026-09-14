class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = n-1;i>=0;i--){
            ans += (s[i]-'A'+1)*pow(26,(n-1)-i);
        }
        return ans;
    }
};