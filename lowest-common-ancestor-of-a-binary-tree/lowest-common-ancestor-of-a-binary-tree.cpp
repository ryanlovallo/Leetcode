/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
    
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        
        if (root == p || root == q) return root;
        
        TreeNode* l = dfs(root->left, p, q);
        TreeNode* r = dfs(root->right, p, q);
        
        if (l && r) return root;
        return (l) ? l : r;
        /*
        if root = p or root = q
            return root
        left = dfs(root->left)
        right = dfs(root->right)
        
        if (left && right) return root
        return (left) ? left : right;
        */
    }
};