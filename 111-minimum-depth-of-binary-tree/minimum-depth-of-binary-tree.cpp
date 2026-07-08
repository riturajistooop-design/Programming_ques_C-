class Solution {
public:
    void helper(TreeNode* root,int level,int& count){
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL){
            count = min(count,level);
            return;
        }
        helper(root->left,level+1,count);
        helper(root->right,level+1,count);
    }
    int minDepth(TreeNode* root) {
        int count = INT_MAX;
        helper(root,1,count);
        if(count == INT_MAX) return 0;
        return count;
    }
};