class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> s;
        int n = nums2.size();
        for(int i=0;i<n;i++){
            s[nums2[i]] = i;
        }
        int m = nums1.size();
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            int x = nums2[i];
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()) nums2[i] = -1;
            else nums2[i] = st.top();
            st.push(x);
        }
        for(int i=0;i<m;i++){
            int idx = s[nums1[i]];
            nums1[i] = nums2[idx];
        }
        return nums1;
    }
};