class Solution {
public:
    vector<int> r = {-1,-1,-1, 0, 0, 1, 1, 1};
    vector<int> c = {-1, 0, 1, -1,1,-1, 0, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // vector<vector<bool>> visited(n, vector<int>(n, false));
        queue<vector<int>> q;
        if (grid[0][0] == 1) return -1;
        grid[0][0] = 1;
        q.push({0,0,1});
        
        while (!q.empty()) {
            int row = q.front()[0], col = q.front()[1], steps = q.front()[2];
            q.pop();
            
            if (row == n-1 && col == n-1) return steps;
                
            for (int i = 0; i < 8; ++i) {
                int rnext = r[i] + row;
                int cnext = c[i] + col;
                if (rnext >= 0 && rnext < n && cnext >= 0 && cnext < n && grid[rnext][cnext] == 0) {
                    grid[rnext][cnext] = 1;
                    q.push({rnext, cnext, steps+1});
                }
            }
        }
        return -1;
    }
};