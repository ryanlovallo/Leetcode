class Solution {
public:
    
    vector<int> rv = {0, 1, 0, -1};
    vector<int> cv = {1, 0, -1, 0};
    unordered_map<int, int> areaSizes;  // group # --> size of group
    
    int largestIsland(vector<vector<int>>& grid) {
        int groupNum = 2;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 1) continue;
                dfs(grid, groupNum, i, j);
                groupNum++;
            }
        }
        int maxArea = -1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) continue;
                
                unordered_set<int> has_seen;
                int curSum = 1;
                for (int k = 0; k < 4; ++k) {
                    int row = i + rv[k], col = j + cv[k];
                    if (row < 0 || col < 0 || row >= grid.size() || col >= grid.size()) continue;
                    if (grid[row][col] != 0 && has_seen.find(grid[row][col]) == has_seen.end()) {
                        curSum += areaSizes[grid[row][col]];
                        has_seen.insert(grid[row][col]);
                    }
                }
                maxArea = max(maxArea, curSum);
            }
        }
        return (maxArea == -1) ? (grid.size() * grid.size()) : maxArea;
    }
    
    void dfs(vector<vector<int>>& grid, int groupNum, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) return;
        
        grid[r][c] = groupNum;
        areaSizes[groupNum]++;
        
        for (int i = 0; i < 4; ++i) {
            dfs(grid, groupNum, r + rv[i], c + cv[i]);
        }
    }
};
