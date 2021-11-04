class Solution {
public:
    
    unordered_map<int,int> sizes; // #grid id --> size
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int id = 2;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; ++c) {
                if(grid[r][c] != 1) continue;
                dfs(grid, r, c, id);
                id++;
            }
        }
        int curSum, maxSum = 0;
        bool found = false;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; ++c) {
                if(grid[r][c] != 0) continue;
                found = true;
                curSum = 0;
                unordered_set<int> idSeen;
                
                if (r-1 >= 0 && grid[r-1][c] != 0 && idSeen.find(grid[r-1][c]) == idSeen.end()) {
                    curSum += sizes[grid[r-1][c]];
                    idSeen.insert(grid[r-1][c]);
                }
                if (r+1 < rows && grid[r+1][c] != 0 && idSeen.find(grid[r+1][c]) == idSeen.end()) {
                    curSum += sizes[grid[r+1][c]];
                    idSeen.insert(grid[r+1][c]);
                }
                if (c-1 >= 0 && grid[r][c-1] != 0 && idSeen.find(grid[r][c-1]) == idSeen.end()) {
                    curSum += sizes[grid[r][c-1]];
                    idSeen.insert(grid[r][c-1]);
                }
                if (c+1 < cols && grid[r][c+1] != 0 && idSeen.find(grid[r][c+1]) == idSeen.end()) {
                    curSum += sizes[grid[r][c+1]];
                    idSeen.insert(grid[r][c+1]);
                }
                maxSum = max(maxSum, curSum+1);
            }
        }
        if (!found) return rows*cols;
        return maxSum;
        
        // next dfs, check to see if there is a 0- not previous one
    }
    
    void dfs(vector<vector<int>> &grid, int r, int c, int id) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1) return;
        
        // we now know grid[r][c] = 1
        grid[r][c] = id;
        sizes[id]++;
        
        dfs(grid, r-1, c, id);
        dfs(grid, r+1, c, id);
        dfs(grid, r, c-1, id);
        dfs(grid, r, c+1, id);
    }
};