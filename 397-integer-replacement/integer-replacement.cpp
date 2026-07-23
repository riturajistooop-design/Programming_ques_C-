class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        if(n == INT_MAX){
            count+=2;
            n = 1073741824;
        }
        while(n!=1){
            if(n%2==0) {count++; n/=2;}
            else{
                if(((n+1)/2)%2==0 && n!=3 ){
                    n = n+1;
                    count++;
                }
                else{
                    n = n-1;
                    count++;
                }
            }
        }
        return count;
    }
};