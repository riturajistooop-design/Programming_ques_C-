class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        int ans = 0;
        for(int i=0;i<n;i++){
            set.clear();
            for(int j=i;j<n;j++){
                set.insert(nums[j]);
                int d = set.size();
                ans += d*d;
            }
        }
        return ans;
    }
};