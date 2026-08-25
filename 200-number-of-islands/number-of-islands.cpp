class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j,int& m, int& n){
        queue< pair<int,int> > q;
        grid[i][j] = '2';
        q.push({i,j});
        while(!q.empty()){
            auto temp = q.front();
            int row = temp.first;
            int col = temp.second;
            // if(grid[row][col]== '1') grid[row][col] = '-1';

            if(row != 0 && grid[row-1][col] == '1') {q.push({row-1,col}); grid[row-1][col] = '2';}
            if(col != 0 && grid[row][col-1] == '1') {q.push({row,col-1}); grid[row][col-1] = '2';}
            if(row != m-1 && grid[row+1][col] == '1') {q.push({row+1,col}); grid[row+1][col] = '2';}
            if(col != n-1 && grid[row][col+1] == '1') {q.push({row,col+1}); grid[row][col+1] = '2';}
            q.pop();
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> visited(m,vector<int> (n,-1));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    bfs(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};