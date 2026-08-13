class Solution {
public:
    typedef pair<TreeNode*,int> pti;
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pti> q;
        q.push({root,1});
        vector<double> ans;
        int level = 1;
        int count = 0;
        vector<int> row;
        while(!q.empty()){
            pti temp = q.front();
            q.pop();
            if(temp.second != level){
                long sum = 0;
                for (int v : row) sum += v;
                ans.push_back(double(sum) / count);
                row.clear();
                row.push_back(temp.first->val);
                count = 1;
                level++;
            }
            else{
                count++;
                row.push_back(temp.first->val);
            }
            if(temp.first->left){
                q.push({temp.first->left,temp.second+1});
            }
            if(temp.first->right){
                q.push({temp.first->right,temp.second+1});
            }
        } 
        long sum = 0;
        for (int v : row) sum += v;
        ans.push_back(double(sum) / count);
        return ans;
    }
};