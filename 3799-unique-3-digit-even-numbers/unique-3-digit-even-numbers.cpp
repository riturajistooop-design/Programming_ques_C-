class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            map[digits[i]]++;
        }
        for(int i=100;i<1000;i+=2){
            int temp = i;
            int a = temp%10;
            temp = temp/10;
            int b = temp%10;
            temp = temp/10;
            int c = temp;
            if(map.find(a)!=map.end()){
                map[a]--;
                if(map[a]==0) map.erase(a);
                if(map.find(b)!=map.end()){
                    map[b]--;
                    if(map[b]==0) map.erase(b);
                    if(map.find(c)!=map.end()) ans.push_back(i);
                    map[b]++;
                }
                map[a]++;
            }
        }
        return ans.size();
    }
};