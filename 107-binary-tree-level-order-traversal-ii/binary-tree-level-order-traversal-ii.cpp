class Solution {
public:
    void helper(TreeNode* root, vector<vector<int>>& ans,int level){
        if(root == NULL) return;
        ans[level].push_back(root->val);
        helper(root->left,ans,level+1);
        helper(root->right,ans,level+1);
    }
    int level(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans(level(root));
        helper(root,ans,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};