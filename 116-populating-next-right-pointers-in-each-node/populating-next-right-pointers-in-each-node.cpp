class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp){
                temp->next = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            else{
                if(q.size()!=0)q.push(NULL);
            }
        }
        return root;
    }
};