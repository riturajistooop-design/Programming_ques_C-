class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int sum = 0;
        int total = 0;
        
        for(int i = 0; i < n; i++){
            prefix[i] = sum;
            sum += nums[i];
            total += nums[i];
        }
        for(int i = 0; i < n; i++){
            suffix[i] = total - nums[i];
            total -= nums[i];
        }
        for(int i = 0; i < n; i++){
            prefix[i] = abs(prefix[i] - suffix[i]);
        }
        return prefix;
    }
};