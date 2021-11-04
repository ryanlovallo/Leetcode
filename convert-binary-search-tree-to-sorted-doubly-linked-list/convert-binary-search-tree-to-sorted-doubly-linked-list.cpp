/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    
    Node* first;
    Node* last;
    
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        first = nullptr;
        last = nullptr;
        getOrder(root);
        first->left = last;
        last->right = first;
        return first;
    }
    
    void getOrder(Node* root) {
        if (!root) return;
        
        getOrder(root->left);
        
        if (first) {
            last->right = root;
            root->left = last;
        } else {
            first = root;
        }
        
        last = root;
        getOrder(root->right);
    } 
};







