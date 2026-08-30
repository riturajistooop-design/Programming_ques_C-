class Solution {
public:
    int mx = 0;
    int m;
    int n;
    int bfs(vector<vector<int>>& grid,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 0;
        int size = 1;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            if(row!=0 && grid[row-1][col] == 1){q.push({row-1,col}); grid[row-1][col]=0;size++;}
            if(row!=m-1 && grid[row+1][col] == 1){q.push({row+1,col}); grid[row+1][col]=0;size++;}
            if(col!=0 && grid[row][col-1] == 1){q.push({row,col-1}); grid[row][col-1]=0;size++;}
            if(col!=n-1 && grid[row][col+1] == 1){q.push({row,col+1}); grid[row][col+1]=0;size++;}
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) mx = max(mx,bfs(grid,i,j));
            }
        }
        return mx;
    }
};