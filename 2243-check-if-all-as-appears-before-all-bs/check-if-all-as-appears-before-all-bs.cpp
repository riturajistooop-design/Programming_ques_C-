class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        bool flag = false;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(flag == true){
                    return false;
                }
            }
            else{
                flag = true;
            }
        }
        return true;
    }
};