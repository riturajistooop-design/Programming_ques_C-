class Solution {
public:
    int ans;
    int  m;
    int n;
    void bfs(vector<vector<int>>& grid, int i,int j){
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int a = temp.first;
            int b = temp.second;
            if(a<0 || a>=m || b<0 || b>=n){
                ans++;
                continue;
            }
            if(grid[a][b]==0){
                ans++;
                continue;
            }
            if(visited.find({a,b})==visited.end()){
                visited.insert({a,b});
            }
            else continue;
            q.push({a+1,b});
            q.push({a-1,b});
            q.push({a,b+1});
            q.push({a,b-1});
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs(grid,i,j);
                    return ans;
                }
            }
        }
        return ans;
    }
};