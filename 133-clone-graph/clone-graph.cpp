class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> visited; // original -> clone

        Node* clone = new Node(node->val);
        visited[node] = clone;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // create clone for unseen neighbor
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // link current clone to neighbor's clone (existing or just created)
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }

        return clone;
    }
};