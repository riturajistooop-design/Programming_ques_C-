class Solution {
public:
    int digits(int num){
        int ans = 1;
        while(num!=0 && ans++) num/=10;
        return --ans;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++) if((digits(nums[i])%2 == 0) && ans++);
        return --ans;
    }
};