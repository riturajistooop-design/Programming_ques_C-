class Solution {
public:
    static bool cmp(int a,int b){
        if(a>b) return true;
        else return false;
    }
    long long gcdSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(nums[i],mx);
            nums[i] = gcd(nums[i],mx);
        }
        sort(nums.begin(),nums.end(),cmp);
        int i=0;
        int j = n-1;
        while(i<j){
            sum += gcd(nums[i],nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};