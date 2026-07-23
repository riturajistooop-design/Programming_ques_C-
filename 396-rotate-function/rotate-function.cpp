class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            ans += i*nums[i];
        }
        long long mx = ans;
        for(int i = n-1;i>=1;i--){
            ans += sum;
            ans -= n*nums[i];
            if(ans>mx) mx = ans;
        }
        return mx;
    }
};