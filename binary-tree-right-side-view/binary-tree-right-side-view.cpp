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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
  
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        unordered_set<int> layersSeen;
        vector<int> res;

        while(!q.empty()) {
            pair<TreeNode*, int> cur = q.front(); 
            q.pop();
            if (layersSeen.find(cur.second) == layersSeen.end()) {
                res.push_back(cur.first->val);
                layersSeen.insert(cur.second);
            }
            if (cur.first->right) {
                q.push(make_pair(cur.first->right, cur.second + 1)); 
            } 
            if (cur.first->left) {
                q.push(make_pair(cur.first->left, cur.second + 1)); 
            } 
        }
        return res;
    }
};