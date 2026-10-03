class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = 0;
        int left = 0;
        int right = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') left++;
            else right++;
            if(right>left){
                left = 0;
                right = 0;
                continue;
            }
            if(left==right) ans = max(ans,right);
        }
        left = 0;
        right = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') left++;
            else right++;
            if(left>right){
                left = 0;
                right = 0;
                continue;
            }
            if(left==right) ans = max(ans,left);
        }
        return ans*2;
    }
};