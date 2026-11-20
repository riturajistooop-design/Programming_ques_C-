class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int r[26];
        string s[3]= {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for(int i=0; i<3; i++)
            for(auto ch: s[i]) r[ch-'a']=i;
        vector<string> ans;

        for(auto &it: words)
        {
            int row=r[tolower(it[0])-'a'];
            bool flag=true;

            for(auto ch: it) if(r[tolower(ch)-'a'] !=row) {flag=false; break;}

            if(flag) ans.push_back(it);
        }

        return ans;
   }
};