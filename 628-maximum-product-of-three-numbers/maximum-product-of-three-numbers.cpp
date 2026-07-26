class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long option1 = (long long)nums[n-1] * nums[n-2] * nums[n-3];
        long long option2 = (long long)nums[0] * nums[1] * nums[n-1];
        return (int)max(option1, option2);
    }
};