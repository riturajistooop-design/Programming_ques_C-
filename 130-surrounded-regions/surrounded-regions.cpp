class Solution {
public:
    int m;
    int n;
    void bfs(vector<vector<char>>& board,int row,int col,vector<vector<bool>>& visited,bool surround,bool check){
        queue<pair<int,int>> q;
        bool boundary = false;

        vector<vector<bool>> local;                 // NEW: local tracker, only for the detection pass
        if(!check) local.assign(m, vector<bool>(n, false));

        auto& seen = check ? visited : local;        // NEW: pick tracker based on which pass this is
        seen[row][col] = true;                        // NEW: mark start cell immediately
        q.push({row,col});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int i = temp.first;
            int j = temp.second;

            // removed: if(check) visited[i][j] = true;   <- moved to push-time below
            if(check && surround) board[i][j] = 'X';

            if(!check && (i==0 || j==0 || i==m-1 || j==n-1)) boundary = true;
            // removed the early "recurse + return" here — just record boundary, keep exploring

            if(i!=0 && board[i-1][j]=='O' && !seen[i-1][j]){ seen[i-1][j]=true; q.push({i-1,j}); }
            if(j!=0 && board[i][j-1]=='O' && !seen[i][j-1]){ seen[i][j-1]=true; q.push({i,j-1}); }
            if(i!=m-1 && board[i+1][j]=='O' && !seen[i+1][j]){ seen[i+1][j]=true; q.push({i+1,j}); }
            if(j!=n-1 && board[i][j+1]=='O' && !seen[i][j+1]){ seen[i][j+1]=true; q.push({i,j+1}); }
        }

        if(!check){
            if(boundary) bfs(board,row,col,visited,false,true);   // CHANGED: touches edge -> surround=false (stay 'O')
            else         bfs(board,row,col,visited,true,true);    // CHANGED: enclosed -> surround=true (convert)
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();               // FIXED: was board.size()
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && !visited[i][j]) bfs(board,i,j,visited,false,false);
            }
        }
    }
};