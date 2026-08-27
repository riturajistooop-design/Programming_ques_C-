class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        unordered_set<int> s;
        unordered_set<int> t;
        for(int i=0;i<num1.size();i++){
            s.insert(num1[i]);
        }
        for(int i=0;i<num2.size();i++){
            t.insert(num2[i]);
        }
        vector<int> ans;
        for(int ele : s){
            if(t.find(ele)!=t.end()){
                ans.push_back(ele);
                t.erase(ele);
            }
        }
        return ans;
    }
};