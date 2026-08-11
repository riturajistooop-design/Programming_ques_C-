class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        // 1. Sum the consecutive prefix in ORIGINAL order
        long long sum = nums[0];
        int i = 1;
        while (i < n && nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            i++;
        }

        // 2. Find smallest integer >= sum not present in nums
        unordered_set<int> present(nums.begin(), nums.end());
        while (present.count(sum)) {
            sum++;
        }

        return sum;
    }
};