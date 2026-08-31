class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        ListNode* temp = head;
        int maxcount = 0;
        int mincount = 0;
        int mindis = INT_MAX;
        int maxdis = -1;
        bool found = false;
        while(temp->next->next !=NULL){
            if((temp->val<temp->next->val && temp->next->val>temp->next->next->val) ||
            (temp->val>temp->next->val && temp->next->val<temp->next->next->val)){
                if(found == false){
                    found = true; 
                    temp = temp->next;
                }
                else{
                    mincount++;
                    mindis = min(mincount,mindis);
                    maxcount++;
                    maxdis = max(maxdis,maxcount);
                    mincount=0;
                    temp = temp->next;
                }
            }
            else{
                if(found==true){
                    mincount++;
                    maxcount++;
                }
                temp = temp->next;
            }
        }
        ans[0] = (mindis!=INT_MAX) ? mindis : -1;
        ans[1] = (maxdis!=-1) ? maxdis : -1;
        return ans;
    }
};