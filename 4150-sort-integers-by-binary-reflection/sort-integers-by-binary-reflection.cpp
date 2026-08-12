class Solution {
public:
    static int revBit(int n){
        int ans = 0;
        while(n != 0){
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }
        return ans;
    }

    static bool cmp(int a, int b){
        int ra = revBit(a), rb = revBit(b);
        if (ra != rb) return ra < rb;   // ascending by reflection
        return a < b;                   // tiebreak: smaller original first
    }

    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};