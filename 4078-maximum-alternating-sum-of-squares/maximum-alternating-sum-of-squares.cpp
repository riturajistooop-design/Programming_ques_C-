class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        int mid = n/2;
        long long ans = 0;
        for(int i=n-1;i>=0;i--){
            if(i>=mid) ans += nums[i];
            else ans-= nums[i];
        }
        return ans;
    }
};