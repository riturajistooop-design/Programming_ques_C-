class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = 0;
        int ans = 0;
        for(int i = n-1;i>=0;i--){
            ans = max(ans,mx-prices[i]);
            if(prices[i]>mx) mx = prices[i];
        }
        return ans;
    }
};