class Solution {
    public:
    
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;

        int num = n;
        while(num>0)
        {
            int rem = num%10;
            digitSum = digitSum + rem;
            digitProduct = digitProduct * rem;
            num = num/10; 
        }

        int sum = digitSum + digitProduct;

        if(n%sum == 0)
        {
            return true;
        }
        return false;
    }
};