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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        TreeNode* cur;
        int depth;
        while(!q.empty()) {
            cur = q.front().first;
            depth = q.front().second;
            q.pop();
            if (depth >= res.size()) {
                res.push_back(cur->val);
            } else {
                res[depth] = max(res[depth], cur->val);
            }
            
            if (cur->left) q.push(make_pair(cur->left, depth+1));
            if (cur->right) q.push(make_pair(cur->right, depth+1));
        }
        return res;
    }
};