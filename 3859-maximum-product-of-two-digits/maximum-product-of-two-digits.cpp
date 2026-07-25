class Solution {
public:
    int maxProduct(int n) {
        int mx = -1;
        int sec_mx = -1;
        while(n!=0){
            if(n%10 >= mx){
                sec_mx = mx;
                mx = n%10;
            }
            else if(n%10 > sec_mx) sec_mx = n%10;
            n /= 10;
        }
        return mx*sec_mx;
    }
};