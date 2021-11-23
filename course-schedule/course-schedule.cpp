class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> incEdges;
        unordered_map<int, vector<int>> adjList;
        int numLeft = numCourses;
        
        for (vector<int>& v : prerequisites) {
            adjList[v[1]].push_back(v[0]);
            incEdges[v[0]]++; 
        }
        
        queue<int> noEdges;
        for (int i = 0; i < numCourses; ++i) {
            if (incEdges.find(i) == incEdges.end()) noEdges.push(i);
        }
        
        int cur;
        while (!noEdges.empty()) {
            cur = noEdges.front();
            noEdges.pop();
            for (int i = 0; i < adjList[cur].size(); ++i) {
                if (--incEdges[adjList[cur][i]] == 0) {
                    noEdges.push(adjList[cur][i]);
                }
            }
            --numCourses;
        }
        
        return numCourses == 0;
    }
};