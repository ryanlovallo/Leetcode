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
        unordered_map<Node*, Node*> mp;
        
        
        Node* dummy = new Node(0);
        Node* runner = head;
        Node* prev = dummy;
        
        while(runner) {
            Node* n = new Node(runner->val);
            mp[runner] = n;
            n->random = runner;
            prev->next = n;
            prev = prev->next;
            runner = runner->next;
        }
        
        runner = head;
        prev = dummy;
        while(runner) {
            prev->next->random = mp[runner->random];
            runner = runner->next;
            prev = prev->next;
        }
        return dummy->next;
    }
};