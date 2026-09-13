class Solution {
public:
    vector<vector<int>> set;
    int checkOverlap(int i,int j,vector<vector<int>>& img1, vector<vector<int>>& img2){
        int n = img1.size();
        int sz = set.size();
        int ans = 0;
        for(int s = 0;s<sz;s++ ){
            if(set[s][0]+i >=n || set[s][1] + j >=n || set[s][0] + i <0 || set[s][1] + j <0) continue;
            if(img1[set[s][0]][set[s][1]] == img2[set[s][0]+i][set[s][1] + j] == 1) ans++;
        }
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int mx = 0;
        int n = img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j] == 1) set.push_back({i,j});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mx = max(mx,checkOverlap(i,j,img1,img2));
                mx = max(mx,checkOverlap(i-(n-1),j-(n-1),img1,img2));
                mx = max(mx,checkOverlap(i-(n-1),j,img1,img2));
                mx = max(mx,checkOverlap(i,j-(n-1),img1,img2));
            }
        }
        return mx;
    }
};