class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        int n = s.length();
        while(i<n){
            if(i+k < n)reverse(s.begin() + i,s.begin()+i+k);
            else reverse(s.begin()+i,s.end());
            i += 2*k;
        }
        return s;
    }
};