/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<int, Node*> copies;
        vector<Node*> nodes;
        
        queue<Node*> q;
        q.push(node);
        Node* cur;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            
            Node* n = new Node(cur->val, cur->neighbors);
            copies[cur->val] = n;
            nodes.push_back(n);
            
            for (auto& nd : cur->neighbors) {
                if (copies.find(nd->val) == copies.end()) q.push(nd);
            }
        }
        
        for (auto& n : nodes) {
            for (int i = 0; i < n->neighbors.size(); ++i) {
                n->neighbors[i] = copies[n->neighbors[i]->val];
            }
        }
        return nodes.front();
        
    }
};