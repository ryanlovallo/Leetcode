/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<int> seen;
        Node* first = dfs(p, q, seen);
        return (first) ? first : dfs(q, p, seen);
    }
    
    Node* dfs(Node* n, Node* find, unordered_set<int> &seen) {
        if (!n) return nullptr;
        
        if (n == find || seen.find(n->val) != seen.end()) return n;
        seen.insert(n->val);
        return dfs(n->parent, find, seen);
    }
};