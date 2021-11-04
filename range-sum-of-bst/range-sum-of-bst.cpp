/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        
        stack<TreeNode*> s; 
        s.push(root); 
        TreeNode* cur;
        while(!s.empty()) {
            cur = s.top();
            s.pop(); 
            if (cur->val >= low && cur->val <= high) sum += cur->val;
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }
        return sum;
    }
    
};