class Solution {
public:
    int minimumChairs(string s) {
        int count = 0;
        int mx = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='E'){
                count++;
                mx = max(count,mx);
            }
            else count--;
        }
        return mx;
    }
};