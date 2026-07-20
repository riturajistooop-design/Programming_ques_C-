class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k %= (m * n); 
        int j = 0;
        while(j<k){
            int temp = grid[m-1][n-1];
            for(int i=0;i<m*n;i++){
                int row = i/n;
                int column = i%n;
                int a = grid[row][column];
                grid[row][column] = temp;
                temp = a;
            }
            j++;
        }
        
        return grid;
    }
};