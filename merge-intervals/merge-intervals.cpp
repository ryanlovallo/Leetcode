class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
           return (a[0] != b[0]) ? a[0] < b[0] : a[1] < b[1]; 
        });
        
        vector<vector<int>> res;
        
        int i = 0, maxEnd = 0, minStart = 0;
        
        while (i < intervals.size()) {
            maxEnd = intervals[i][1];
            minStart = intervals[i][0];
            if (i == intervals.size()-1) {
                res.push_back({intervals[i][0],intervals[i][1]});
                break;
            }
            while (i < intervals.size()-1) {
                if (intervals[i+1][0] > maxEnd) break;
                maxEnd = max(maxEnd, intervals[i+1][1]);
                ++i;
            } 
            res.push_back({minStart, maxEnd});
            ++i;
        }
        return res;
        
    }
};

/*
[[2,3],[2,6],[1,6],[8,10],[15,18]]
[[1,6],[2,3],[2,6],[4,7],[8,10],[15,18]]
*/