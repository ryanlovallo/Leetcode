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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> pairs;
        dfs(root, 0, 0, pairs);
        
        sort(pairs.begin(), pairs.end(), [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] != v2[0]) return v1[0] < v2[0];
            else if (v1[1] != v2[1]) return v1[1] < v2[1];
            return v1[2] < v2[2];
        });
        vector<vector<int>> res;
        int i = 0, x = pairs.front()[0];
        vector<int> curVec;
        while (i < pairs.size()) {
            if (pairs[i][0] != x) {
                res.push_back(curVec);
                curVec = {};
                x = pairs[i][0];
            }
            curVec.push_back(pairs[i++][2]);
        }
        res.push_back(curVec);
        return res;
    }
    
    void dfs(TreeNode* root, int x, int y, vector<vector<int>>& res) {
        if (!root) return;
        
        vector<int> v = {x, y, root->val};
        
        res.push_back(v);
        
        dfs(root->left, x-1, y+1, res);
        dfs(root->right, x+1, y+1, res);
        return;
    }
};