class Solution {
public:
    void gen(vector<string>& v,string s,int l,int r){
        if(l==0 && r==0){
            v.push_back(s);
            return;
        }
        if(l!=0) gen(v,s+'(',l-1,r);
        if(r>l) gen(v,s+')',l,r-1);
    }
    vector<string> generateParenthesis(int n){
        vector<string> v;
        string s = "";
        gen(v,s,n,n);
        return v;
    }
};