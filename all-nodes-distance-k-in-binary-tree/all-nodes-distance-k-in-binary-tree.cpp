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
    
    unordered_map<TreeNode*,TreeNode*> parents;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfsparent(root, nullptr);
        
        unordered_set<TreeNode*> visited;
        vector<int> res;
        dfs(target, visited, res, k);
        return res;
        
    }
    
    void dfs(TreeNode* cur, unordered_set<TreeNode*>& visited, vector<int>& res, int k) {
        if (!cur || visited.find(cur) != visited.end()) return;
        
        visited.insert(cur);
        if (k == 0) {
            res.push_back(cur->val);
            return;
        }
        
        dfs(cur->left, visited, res, k-1);
        dfs(cur->right, visited, res, k-1);
        dfs(parents[cur], visited, res, k-1);
    }
    
    void dfsparent(TreeNode* cur, TreeNode* prev) {
        if (!cur) return;
        
        parents[cur] = prev;
        dfsparent(cur->left, cur);
        dfsparent(cur->right, cur);
    }
};