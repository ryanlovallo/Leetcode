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
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);

    }   
    
    TreeNode* dfs(TreeNode* root) {
        if (!root) return nullptr;
        
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        
        if (!left && !right && root->val == 0) return nullptr;
        if (!left) root->left = nullptr;
        if (!right) root->right = nullptr;
        
        return root;
        
    }
};