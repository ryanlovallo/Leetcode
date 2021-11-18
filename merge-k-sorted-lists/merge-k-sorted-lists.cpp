/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return nullptr;
        if (lists.size() == 1) {
            return lists[0];
        } else if (lists.size() == 2) {
            return merge(lists[0], lists[1]);
        }
        
        int mid = lists.size()/2;
        vector<ListNode*> first(lists.begin(), lists.begin() + mid);
        vector<ListNode*> second(lists.begin() + mid, lists.end());
        ListNode* a = mergeKLists(first);
        ListNode* b = mergeKLists(second);
        return merge(a, b);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode();
        ListNode* dummy = new ListNode();
        dummy = cur;
        
        while (l1 || l2) {
            if (!l1) {
                cur->next = l2;
                break;
            } else if (!l2) {
                cur->next = l1;
                break;
            } else if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

/*
dummy -> 1 -> 2


4 5
2 7

*/