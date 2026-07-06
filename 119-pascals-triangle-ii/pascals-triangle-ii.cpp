class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0) return {1};
        if(n==1) return {1,1};
        vector<int> dp(n+1,1);
        for(int i=0;i<n+1;i++){
            int prev = 1;
            for(int j=0;j<=i;j++){
                if(j==0) dp[j] = 1;
                else if(j==i) dp[j] = 1;
                else{
                    int temp = dp[j];
                    dp[j] = dp[j] + prev;
                    prev = temp;
                }
            }
        }
        return dp;
    }
};