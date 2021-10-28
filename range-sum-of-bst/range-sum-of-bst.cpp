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
        return getRange(root, low, high);
    }
    
    int getRange(TreeNode* root, int low, int high) {
        if (!root) return 0;
        
        int n = 0;
        if(root->val >= low && root->val <= high) {
            n = root->val;
        }
        
        return n + getRange(root->left, low, high) + getRange(root->right, low, high);
    }
};