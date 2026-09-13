class Solution {
public:
    vector<vector<int>> set;
    int checkOverlap(int i,int j,vector<vector<int>>& img1, vector<vector<int>>& img2){
        int n = img1.size();
        int sz = set.size();
        int ans = 0;
        for(int s = 0;s<sz;s++ ){
            //ele.first-> set[s][0]
            //ele.second->set[s][1]
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
        for(int i=0;i<n;i++){ // right, down and down-right covered;
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
// for(int i = n-1;i>=0;i--){  // up left ans up left covered;
        //     for(int j = n-1;j>=0;j--){
        //         max = max(max,checkOverlap(i-(n-1),j-(n-1),img1,img2)); // -i -j for shifting 
        //     }
        // }
        // // Now Doing up right 
        // for(int i=0;i<n;i++){
        //     for(int j=1;j<n;j++){
        //         max = max()
        //     }
        // }