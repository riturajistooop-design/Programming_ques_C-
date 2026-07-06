class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int mn = INT_MAX;
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        for(int i=1;i<n;i++){
            int m = triangle[i].size();
            for(int j=0;j<m;j++){
                if(j==0) triangle[i][j] += triangle[i-1][j];
                else if(j==m-1) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }
        for(int i = 0;i<triangle[n-1].size();i++){
            mn = min(mn,triangle[n-1][i]);
        }
        return mn;
    }
};