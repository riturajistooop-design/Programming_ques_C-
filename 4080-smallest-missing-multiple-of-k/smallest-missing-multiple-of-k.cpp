class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int num = k;
        int i = 1;
        while(true){
            if(s.find(num*i)==s.end()){
                return num*i;
            }
            i++;
        }
        return -1;
    }
};