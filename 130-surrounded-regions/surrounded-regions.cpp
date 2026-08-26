class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> safe(m, vector<bool>(n, false));
        queue<pair<int,int>> q;

        // Seed with every 'O' on the border
        for (int i = 0; i < m; i++) {
            if (board[i][0]   == 'O' && !safe[i][0])   { safe[i][0]=true;   q.push({i,0}); }
            if (board[i][n-1] == 'O' && !safe[i][n-1]) { safe[i][n-1]=true; q.push({i,n-1}); }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j]   == 'O' && !safe[0][j])   { safe[0][j]=true;   q.push({0,j}); }
            if (board[m-1][j] == 'O' && !safe[m-1][j]) { safe[m-1][j]=true; q.push({m-1,j}); }
        }

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            for (auto& d : dirs) {
                int ni = i+d[0], nj = j+d[1];
                if (ni<0||nj<0||ni>=m||nj>=n) continue;
                if (board[ni][nj] != 'O' || safe[ni][nj]) continue;
                safe[ni][nj] = true;   // mark at push time, not pop time
                q.push({ni,nj});
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O' && !safe[i][j]) board[i][j] = 'X';
    }
};