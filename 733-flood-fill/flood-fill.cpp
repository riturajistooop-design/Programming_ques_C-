class Solution {
public:
    void helper(vector<vector<int>>& image, int sr,int sc,int& color,int paint,int& m,int& n){
        image[sr][sc] = color;
        if((sr+1 < m) && image[sr+1][sc] == paint) {
            helper(image,sr+1,sc,color,paint,m,n);
        }
        if((sr-1 >= 0) && image[sr-1][sc] == paint) {
            helper(image,sr-1,sc,color,paint,m,n);
        }
        if((sc+1 < n) && image[sr][sc+1] == paint) {
            helper(image,sr,sc+1,color,paint,m,n);
        }
        if((sc-1 >= 0) && image[sr][sc-1] == paint) {
            helper(image,sr,sc-1,color,paint,m,n);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size();
        int n = image[0].size();
        helper(image,sr,sc,color,image[sr][sc],m,n);
        return image;
    }
};