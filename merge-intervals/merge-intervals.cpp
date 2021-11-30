class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        for (vector<int>& invl : intervals) {
            if (merged.empty() || merged.back()[1] < invl[0]) {
                merged.push_back(invl);
            } else {
                merged.back()[1] = max(invl[1], merged.back()[1]);
            }
        }
        return merged;
    }
};