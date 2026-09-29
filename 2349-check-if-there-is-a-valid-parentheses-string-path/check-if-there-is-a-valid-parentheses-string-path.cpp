class Solution {
public:
    int m;
    int n;
    int mid;
    bool helper(vector<vector<char>>& grid,int i,int j,int open,int close,vector<vector<vector<int>>>& dp){
        if(i >= m || j >= n) return false;
        if(grid[i][j] == '(') open++;
        else close++;
        if(close > open) return false;
        if(open>mid) return false;
        if(dp[i][j][open-close] != -1) return (bool)dp[i][j][open-close];
        if((i==m-1) && (j==n-1)){
            if(open == close) return true;
            else return false;
        }
        return dp[i][j][open-close] = (helper(grid,i+1,j,open,close,dp) || helper(grid,i,j+1,open,close,dp));
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if((m+n)%2 == 0) return false;
        mid = (m+n-1)/2;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m+n+1,-1)));
        return helper(grid,0,0,0,0,dp);
    }
};