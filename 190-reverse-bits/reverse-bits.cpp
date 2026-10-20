class Solution {
public:
    int reverseBits(int n) {
        int x = n;
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (x & 1);
            x >>= 1;
        }
        return ans;
    }
};