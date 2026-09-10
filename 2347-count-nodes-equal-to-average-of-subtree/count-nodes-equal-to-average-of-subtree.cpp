class Solution {
public:
    int fNodes(TreeNode* root){
        if(root == NULL) return 0;
        else return 1 + fNodes(root->left) + fNodes(root->right);
    }
    int helper(TreeNode* root,int& count){
        if(root == NULL) return 0;
        int total = root->val + helper(root->left,count) + helper(root->right,count);
        int avg = total/fNodes(root);
        if(avg == root->val) count++;
        return total;
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        helper(root,count);
        return count;
    }
};