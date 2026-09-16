class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char,int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        int n = s.length();
        int i = n-1;
        while(i>=0){
            if(i > 0 && val[s[i-1]] < val[s[i]]){
                ans += (val[s[i]] - val[s[i-1]]);
                i-=2;
            }
            else{
                ans += val[s[i]];
                i--;
            }
        }
        return ans;
    }
};