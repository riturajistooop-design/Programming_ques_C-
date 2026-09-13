class Solution {
public:
    // typedef pair<char,int> pci;
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return n;
        unordered_set<char> set;
        int len = 1;
        int ans = 1;
        int i = 0;
        int j = 1;
        set.insert(s[i]);
        while(j<n){
            if(set.find(s[j])!=set.end()){
                ans = max(ans,len);
                while(s[i]!=s[j]){
                    len--;
                    set.erase(s[i]);
                    i++;
                }
                i++;
                j++;
            }
            else{
                set.insert(s[j]);
                j++;
                len++;
            }
        }
        ans = max(ans,len);
        return ans;
    }
};
/*
int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return n;
        unordered_map<char,int> set;
        int len = 0;
        int ans = 1;
        for(int i=0;i<n;i++){
            if(set.find(s[i])!=set.end()){
                ans = max(ans,len);
                len = 0;
                i = set[s[i]];
                set.clear();
            }
            else{
                set.insert({s[i],i});
                len++;
            }
        }
        ans = max(ans,len);
        return ans;
    }
*/