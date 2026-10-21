class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        vector<vector<int>> res(m,vector<int>(n,0));
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j] = original[k];
                k++;
                if(k==s && i==m-1 && j==n-1) return res;
                if(k==s) return {};
            }
        }
        return {};
    }
};