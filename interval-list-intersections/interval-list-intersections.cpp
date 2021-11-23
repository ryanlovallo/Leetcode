class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i1 = 0, i2 = 0;
        vector<vector<int>> res;
        while (i1 < firstList.size() && i2 < secondList.size()) {
            
            int low = max(firstList[i1][0], secondList[i2][0]);
            int high = min(firstList[i1][1], secondList[i2][1]);
            
            if (low <= high) {
                res.push_back({low, high});
            }
            
            if (firstList[i1][1] < secondList[i2][1]) {
                i1++;
            } else {
                i2++;
            }
        }
        return res;
    }
};