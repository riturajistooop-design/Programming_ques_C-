class Solution {
public:
    bool canAliceWin(int n) {
        bool flag = true;
        for(int i=10;i>=0;i--){
            if(n==0 || n<i) return !flag;
            else{
                n-=i;
                flag = !flag;
            }
        }
        return true;
    }
};