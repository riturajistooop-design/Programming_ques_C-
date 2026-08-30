class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int p = 0;
        while(num!=0){
            int bit = num%2;
            if(bit==0) ans += pow(2,p);
            p++;
            num >>= 1;
        }
        return ans;
    }
};