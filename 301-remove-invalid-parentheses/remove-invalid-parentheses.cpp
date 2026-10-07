class Solution {
public:
    int n;
    int mn;
    unordered_set<string> set;
    vector<string> res;
    void helper(string& s,int i,int bal,int rem,string ans){
        if(bal<0) return;
        if(rem>mn) return;
        if(i==n){
            if(bal!=0) return;
            set.insert(ans);
            return;
        }
        if(s[i]=='('){
            helper(s,i+1,bal+1,rem,ans+s[i]);
            helper(s,i+1,bal,rem+1,ans);
        }
        else if(s[i]==')'){
            helper(s,i+1,bal,rem+1,ans);
            helper(s,i+1,bal-1,rem,ans+s[i]);
        }
        else{
            helper(s,i+1,bal,rem, ans+s[i]);
        }

    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        mn = 0;
        int bal = 0;
        int size = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {bal++;size++;}
            else if(s[i]==')') {bal--;size++;}
            else continue;
            if(bal<0){
                mn++;
                bal++;
            }
        }
        mn += bal;
        if(mn>=size){
            string ans = "";
            for(int i=0;i<n;i++){
                if((s[i] != '(') && (s[i] != ')')){
                    ans += s[i];
                }
            }
            return {ans};
        }
        helper(s,0,0,0,"");
        // return res;
        for(auto ele : set){
            res.push_back(ele);
        }
        return res;
    }
};