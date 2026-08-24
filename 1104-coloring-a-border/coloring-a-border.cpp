class Solution {
public:
    set<pair<int,int>> visited;
    void colorBoundary(vector<vector<int>>& grid,int i,int j,int& color,int& clr,vector<vector<int>>& visit){
        if(visit[i][j]!=-1) return;
        visit[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();
        if(grid[i][j] != clr) return;
        if(visited.find({i,j})!=visited.end()) return;
        if(i==0 || i == m-1 || j==0 || j == n-1){
            visited.insert({i,j});
            grid[i][j] = color;
        }
        else if(visited.find({i-1,j})==visited.end() && grid[i-1][j] != clr){
            visited.insert({i,j});
            grid[i][j] = color;
        }
        else if(visited.find({i,j-1})==visited.end() && grid[i][j-1] != clr){
            visited.insert({i,j});
            grid[i][j] = color;
        }
        else if(visited.find({i+1,j})==visited.end() && grid[i+1][j] != clr){
            visited.insert({i,j});
            grid[i][j] = color;
        }
        else if(visited.find({i,j+1})==visited.end() && grid[i][j+1] != clr){
            visited.insert({i,j});
            grid[i][j] = color;
        }
        if(i!=0) colorBoundary(grid,i-1,j,color,clr,visit);
        if(j!=0) colorBoundary(grid,i,j-1,color,clr,visit);
        if(i!=m-1) colorBoundary(grid,i+1,j,color,clr,visit);
        if(j!=n-1) colorBoundary(grid,i,j+1,color,clr,visit);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int i, int j, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,-1));
        int clr = grid[i][j];
        colorBoundary(grid,i,j,color,clr,visit);
        return grid;
    }
};