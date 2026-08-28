class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 1;
        int max = nums[n-1];
        int i = n-2;
        while(i>=0){
            if(nums[i]!=nums[i+1]){
                count++;
                max = nums[i];
                if(count == 3) return max;
            }
            i--;
        }
        if(count == 3) return max;
        else return nums[n-1];
    }
};