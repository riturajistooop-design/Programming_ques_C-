class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = INT_MAX;
        int large = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            small = min(nums[i],small);
            large = max(nums[i],large);
        }
        return gcd(small,large);
    }
};