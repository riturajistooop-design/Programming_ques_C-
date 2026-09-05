class Solution {
public://21
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minv(n);
        int mint=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<mint)mint=nums[i];
            minv[i]=mint;
        }
        int maxt=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxt)maxt=nums[i];
            if(maxt-minv[i]<=k)return i;
        }
        return -1;
    }
};