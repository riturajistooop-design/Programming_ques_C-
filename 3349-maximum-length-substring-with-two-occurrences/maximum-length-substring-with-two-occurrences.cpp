class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int n = s.length();
        int mx = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            if(freq[s[i] -'a']==2){
                freq[s[i]-'a']--;
                while(s[j] != s[i]){
                    freq[s[j]-'a']--;
                    j++;
                }
                j++;
            }
            {
                freq[s[i]-'a']++;
                mx = max(mx,i-j+1);
            }
        }
        return mx;
    }
}; 