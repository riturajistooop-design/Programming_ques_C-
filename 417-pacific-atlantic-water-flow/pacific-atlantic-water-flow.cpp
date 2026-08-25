class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<int>>& heights, int i , int j , vector<vector<bool>>& visited){
        if(visited[i][j]) return;
        visited[i][j] = true;
        if( i!=0 && heights[i-1][j] >= heights[i][j]) dfs(heights,i-1,j,visited);
        if( j!=0 && heights[i][j-1] >= heights[i][j]) dfs(heights,i,j-1,visited);
        if( i!=m-1 && heights[i+1][j] >= heights[i][j]) dfs(heights,i+1,j,visited);
        if( j!=n-1 && heights[i][j+1] >= heights[i][j]) dfs(heights,i,j+1,visited);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool> (n,false));
        vector<vector<bool>> atlantic(m,vector<bool> (n,false));
        for(int i=0;i<n;i++){
            dfs(heights,0,i,pacific);
            dfs(heights,m-1,i,atlantic);
        }
        for(int i=0;i<m;i++){
            dfs(heights,i,0,pacific);
            dfs(heights,i,n-1,atlantic);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};