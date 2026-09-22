class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=2;i<n;i++){
            if(i==2) {nums[i] += nums[0];continue;}
            nums[i] += max(nums[i-2],nums[i-3]);
        }
        return max(nums[n-1],nums[n-2]);
    }
};