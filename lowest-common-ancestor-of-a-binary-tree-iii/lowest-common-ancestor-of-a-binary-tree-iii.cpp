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
        Node* pNode = p;
        Node* qNode = q;
        
        while (qNode != pNode) {
            if (!pNode->parent) pNode = q;
            else pNode = pNode->parent;
            
            if (!qNode->parent) qNode = p;
            else qNode = qNode->parent;
        }
        return pNode;
    }
};