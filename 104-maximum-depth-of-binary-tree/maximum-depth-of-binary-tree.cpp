class Solution {
public:
    void helper(TreeNode* root,int level,int& depth){
        if(root==NULL){
            depth = max(depth,level);
            return;
        }
        helper(root->left,level+1,depth);
        helper(root->right,level+1,depth);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 0;
        helper(root,0,depth);
        return depth;
    }
};