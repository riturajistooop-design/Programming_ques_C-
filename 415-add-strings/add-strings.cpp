class Solution {
public:
    string addStrings(string num1, string num2) {
        // char sum;
        int carry = 0;
        int m = num1.length();
        int n = num2.length();
        int i = m-1;
        int j = n-1;
        string ans = "";
        while(i>=0 && j>=0){
            int s = (num1[i]- '0' + num2[j] - '0' + carry);
            char sum = (char)(s%10 + '0');
            carry = s/10;
            ans = sum + ans;
            i--;
            j--;
        }
        while(i>=0){
            int s = (num1[i]- '0' + carry);
            char sum = (char)(s%10 + '0');
            carry = s/10;
            ans = sum + ans;
            i--;
        }
        while(j>=0){
            int s = (num2[j] - '0' + carry);
            char sum = (char)(s%10 + '0');
            carry = s/10;
            ans = sum + ans;
            j--;
        }
        if(carry!=0) ans = (char)(carry + '0') + ans;
        return ans;
    }
};