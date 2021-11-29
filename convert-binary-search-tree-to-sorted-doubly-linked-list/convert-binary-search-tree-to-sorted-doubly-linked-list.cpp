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
    
    Node* prev;
    Node* first;
    Node* last;
    
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        inorder(root);
        
        prev->right = first;
        first->left = prev;
        return first;
    }
    
    void inorder(Node* root) {
        if (!root) return;
        
        inorder(root->left);
        
        if (!prev) {
            first = root;
        } else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        inorder(root->right);
    }
};