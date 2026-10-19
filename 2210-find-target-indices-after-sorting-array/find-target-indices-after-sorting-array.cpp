class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int sm = 0;
        int tar = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<target) sm++;
            else if(nums[i]==target) tar++;
        }
        if(tar==0) return {};
        vector<int> ans;
        for(int i=sm;i<sm+tar;i++){
            ans.push_back(i);
        }
        return ans;
    }
};