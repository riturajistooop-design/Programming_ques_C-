class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        unordered_map<Node*, Node*> visited;
        queue<Node*> q;

        visited[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            for (Node* nbr : temp->neighbors) {
                if (visited.find(nbr) == visited.end()) {
                    visited[nbr] = new Node(nbr->val);
                    q.push(nbr);
                }
                visited[temp]->neighbors.push_back(visited[nbr]);
            }
        }

        return visited[node];
    }
};