class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool helper(string& s,int i,int bal){
        if(i == n){
            if(bal == 0) return true;
            else return false;
        } 
        if(bal<0) return false;
        if(dp[i][bal]!=-1) return dp[i][bal];
        if(s[i]=='(') return dp[i][bal] = helper(s,i+1,bal+1);
        else if(s[i]==')') return dp[i][bal] = helper(s,i+1,bal-1);
        else{
            return dp[i][bal] = (helper(s,i+1,bal+1) || helper(s,i+1,bal-1) || helper(s,i+1,bal));
        }
    }
    bool checkValidString(string s) {
        n = s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return helper(s,0,0);
    }
};
