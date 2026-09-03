class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int od = INT_MAX;
        int ev = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0 && nums1[i]<ev) ev = nums1[i];
            else if(nums1[i]%2==1 && nums1[i]<od) od = nums1[i];
        }
        if((od == INT_MAX) || (ev == INT_MAX)) return true;
        if(od<ev) return true;
        return false;
    }
};