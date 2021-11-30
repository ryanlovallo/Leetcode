/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> toNew;
        
        Node* runner = head;
        while(runner) {
            Node* newNode = new Node(runner->val);
            toNew[runner] = newNode;
            newNode->random = runner->random;
            newNode->next = runner->next;
            runner = runner->next;
        }
        
        runner = head;
        while(runner) {
            Node* newNode = toNew[runner];
            if (runner->next) {
                newNode->next = toNew[newNode->next];
            } else {
                newNode->next = nullptr;
            }
            
            if (runner->random) {
                newNode->random = toNew[newNode->random];
            } else {
                newNode->random = nullptr;
            }
            runner = runner->next;
        }
        return toNew[head];
        
        
        
    }
};