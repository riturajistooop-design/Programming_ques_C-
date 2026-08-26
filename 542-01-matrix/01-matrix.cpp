class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m,vector<int> (n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        int dist = 0;
        while(!q.empty()){
            int s = q.size();
            for(int a = 0;a<s;a++){
                auto temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                if(dis[i][j] == -1)dis[i][j] = dist;
                if(i!=0 && dis[i-1][j] == -1)q.push({i-1,j});
                if(i!=m-1 && dis[i+1][j] == -1)q.push({i+1,j});
                if(j!=0 && dis[i][j-1] == -1) q.push({i,j-1});
                if(j!=n-1 && dis[i][j+1] == -1) q.push({i,j+1});
            }
            dist++;
        }
        return dis;
    }
};