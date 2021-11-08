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
        if (!root || root == q || root == p) return root;
        
        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);
        
        if (left && right) return root;
        else return (left) ? left : right;
    }
    
   
};