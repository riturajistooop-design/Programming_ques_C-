class Solution {
public:
    vector<vector<string>> res;

    bool canPlacequeen(int row,int col,vector<string>& grid){
        int n = grid.size();
        for(int i=0;i<row;i++){ // upr dekh liya
            if(grid[i][col] == 'Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){ // left Diagonal
            if(grid[i][j] == 'Q') return false;
        }
        for(int i=row-1,j=col+1; i>=0 && j<n ; i--,j++){ // right Diagonal
            if(grid[i][j] == 'Q') return false;
        }
        return true;
    }

    void f(int row,vector<string>& grid){
        int n = grid.size();
        if(row == n){
            res.push_back(grid);
            return;
        }
        for(int col=0;col<n;col++){
            if(canPlacequeen(row,col,grid)){
                grid[row][col] = 'Q';
                f(row+1, grid);
                grid[row][col] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n,string(n,'.'));
        f(0,grid);
        return res;
    }
};