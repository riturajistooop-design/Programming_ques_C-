class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total;   // avoid unnecessary full rotations

        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < total; i++) {
            int newPos = (i + k) % total;
            res[newPos / n][newPos % n] = grid[i / n][i % n];
        }
        return res;
    }
};