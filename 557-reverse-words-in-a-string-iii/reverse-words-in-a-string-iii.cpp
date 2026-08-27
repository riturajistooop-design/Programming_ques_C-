class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp;
        stringstream ss(s);
        while(ss >> temp){
            reverse(temp.begin(),temp.end());
            ans += temp + " ";
        }
        ans.pop_back();
        return ans;
    }
};