class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> incEdges;
        unordered_map<int, vector<int>> adjList;
        
        for (vector<int>& v : prerequisites) { 
            adjList[v[1]].push_back(v[0]);
            incEdges[v[0]]++; 
        }
        
        queue<int> noEdges;
        for (int i = 0; i < numCourses; ++i) {
            if (incEdges.find(i) == incEdges.end()) noEdges.push(i);
        }
        
        int cur;
        vector<int> res;
        while (!noEdges.empty()) {
            cur = noEdges.front();
            noEdges.pop();
            for (int i = 0; i < adjList[cur].size(); ++i) {
                if (--incEdges[adjList[cur][i]] == 0) {
                    noEdges.push(adjList[cur][i]);
                }
            }
            
            res.push_back(cur);
        }
        
        if (res.size() == numCourses) return res;
        return {};

    }
};