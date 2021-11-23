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
    vector<TreeNode*> inorder;
    TreeNode* balanceBST(TreeNode* root) {
        inord(root);
        return build(0, inorder.size()-1);
    }
    
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right-left)/2;
        
        inorder[mid]->left = build(left, mid-1);
        inorder[mid]->right = build(mid+1, right);
        return inorder[mid];
    }
    
    void inord(TreeNode* root) {
        if (!root) return;
        
        inord(root->left);
        inorder.push_back(root);
        inord(root->right);
    }
};