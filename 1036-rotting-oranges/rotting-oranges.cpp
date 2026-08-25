class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) { // Applying Multi Source BFS
        queue<pair<int,int>> q;
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){ // pushing minute 0 rotten in queue
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty()){
            int s = q.size(); // to know the length of last stage
            bool flag = false; 
            for(int a=0;a<s;a++){
                auto temp = q.front();
                int i = temp.first;
                int j = temp.second;
                q.pop();
                if(i!=0 && grid[i-1][j] == 1) {q.push({i-1,j});grid[i-1][j]=2;flag = true;}
                if(j!=0 && grid[i][j-1] == 1) {q.push({i,j-1});grid[i][j-1]=2;flag = true;}
                if(i!=m-1 && grid[i+1][j] == 1) {q.push({i+1,j});grid[i+1][j]=2;flag = true;}
                if(j!=n-1 && grid[i][j+1] == 1) {q.push({i,j+1});grid[i][j+1]=2;flag = true;}
            }
            if(flag)ans++;
        }
        for(int i=0;i<m;i++){ // pushing minute 0 rotten in queue
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) return -1; 
            }
        }
        return ans;
    }
};