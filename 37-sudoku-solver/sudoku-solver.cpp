class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col , int num){
        for(int i=0;i<9;i++){ // up -> down
            if(board[i][col] - '0' == num) return false;
        }
        for(int i=0;i<9;i++){ // left -> right
            if(board[row][i] - '0' == num) return false;
        }
        int x = 3*(row/3);
        int y = 3*(col/3);
        for(int i=x;i<x+3;i++){  // Small Box
            for(int j=y;j<y+3;j++){
                if(board[i][j] - '0' == num) return false;
            }
        }
        return true;
    }
    bool f(int r,int c,vector<vector<char>>& board){
        if(r==9) return true;
        if(c==9) return f(r+1,0,board);
        if(board[r][c] != '.') return f(r,c+1,board);
        for(int j=1;j<=9;j++){
            if(isSafe(board,r,c,j)){
                board[r][c] = '0' + j;
                bool flag = f(r,c+1,board);
                if(!flag) board[r][c] = '.';
                else return true;
            } 
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(0,0,board);
    }
};