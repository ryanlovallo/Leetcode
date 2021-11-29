class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int curMax = INT_MIN;
        vector<int> res;
        
        for (int i = heights.size()-1; i >= 0; --i) {
            if (heights[i] > curMax) {
                res.push_back(i);
                curMax = heights[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};