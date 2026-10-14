class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum) return "";
        int count = 0;
        int s = 0;
        string ans = "";
        while(count<num && (s+9)<sum){
            count++;
            s+=9;
            ans +='9';
        }
        if(count<num){
            int a = sum-s;
            ans +=(char)('0' + a);
            count++;
            s+=a;
        }
        while(count!=num){
            ans += '0';
            count++;
        }
        return ans;
    }
};