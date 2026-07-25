class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        vector<int> fib = {1,1,2};
        int count = 3;
        while(count != n){
            int a = fib[2];
            fib[2] = fib[2] + fib[1];
            fib[0] = fib[1];
            fib[1] = a;
            count++;
        }
        return fib[2];
    }
};