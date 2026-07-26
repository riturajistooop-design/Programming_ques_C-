class Solution {
public:
    int dp[100005][10][2];
    int f(vector<int>& prices, int i,int k,bool flag){
        if(i==prices.size()) return 0;
        if(dp[i][k][flag] != -1) return dp[i][k][flag];
        int ans = INT_MIN;
        ans = f(prices,i+1,k,flag);
        if(flag){
            ans = max(ans,prices[i] + f(prices,i+1,k-1,false));
        } else{
            if(k>0){
                ans = max(ans,f(prices,i+1,k,true)- prices[i]);
            }
        }
        return dp[i][k][flag] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return f(prices,0,2,false);
    }
};