class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        for(int a=0;a<m;a++){
            bool flag = false;
            for(int b=0;b<n;b++){
                if(grid[a][b] == 1){
                    queue<pair<int,int>> q;
                    q.push({a,b});
                    grid[a][b] = -1;
                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();
                        int i = temp.first;
                        int j = temp.second;
                        if(i!=0 && grid[i-1][j] == 1) {q.push({i-1,j}); grid[i-1][j] = -1;}
                        if(j!=0 && grid[i][j-1] == 1) {q.push({i,j-1}); grid[i][j-1] = -1;}
                        if(i!=m-1 && grid[i+1][j] == 1) {q.push({i+1,j}); grid[i+1][j] = -1;}
                        if(j!=n-1 && grid[i][j+1] == 1) {q.push({i,j+1}); grid[i][j+1] = -1;}
                    }
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    visited[i][j] = true;
                    if(i!=0 && grid[i-1][j] != 1) q.push({i,j});
                    else if(j!=0 && grid[i][j-1] != 1) q.push({i,j});
                    else if(i!=m-1 && grid[i+1][j] != 1) q.push({i,j});
                    else if(j!=n-1 && grid[i][j+1] != 1) q.push({i,j});
                }
            }
        }
        // Main multi Source BFS starts here
        int dis = 0;
        while(!q.empty()){
            int s = q.size();
            for(int a=0;a<s;a++){
                auto temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                if(grid[i][j] == -1) return dis-1;
                if(i!=0 && !visited[i-1][j] && grid[i-1][j] != 1) {q.push({i-1,j}); visited[i-1][j] = true;}
                if(j!=0 && !visited[i][j-1] && grid[i][j-1] != 1) {q.push({i,j-1}); visited[i][j-1] = true;}
                if(i!=m-1 && !visited[i+1][j] && grid[i+1][j] != 1) {q.push({i+1,j}); visited[i+1][j] = true;}
                if(j!=n-1 && !visited[i][j+1] && grid[i][j+1] != 1) {q.push({i,j+1}); visited[i][j+1] = true;}
            }
            dis++;
        }
        return -1;
    }
};