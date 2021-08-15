class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), []( vector<int>& lhs, vector<int>& rhs) {
            double lhs_dist = pow(lhs[0],2) + pow(lhs[1],2);
            double rhs_dist = pow(rhs[0],2) + pow(rhs[1],2);
            return lhs_dist < rhs_dist;
        });
        
        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(points[i]);
        }
        return res;
    }
};