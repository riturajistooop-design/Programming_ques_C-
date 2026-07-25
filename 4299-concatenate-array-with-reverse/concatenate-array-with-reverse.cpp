class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        int i=0;
        int j = 2*n-1;
        while(i<n){
            ans[i] = ans[j] = nums[i];
            i++;
            j--;
        }
        return ans;
    }
};