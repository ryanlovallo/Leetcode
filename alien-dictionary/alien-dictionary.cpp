class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> incEdges;
        unordered_set<char> letters;
        
        for (string& s : words) {
            for (char& c : s) {
                incEdges[c] = 0;
            }
        }
        
        string s1, s2;
        int i1, i2;
        for(int i = 0; i < words.size()-1; ++i) {
            s1 = words[i], s2 = words[i+1];
            i1 = 0, i2 = 0;
            
            while (i1 < s1.size() && i2 < s2.size()) {
                if (s1[i1] != s2[i2]) {
                    adjList[s1[i1]].push_back(s2[i2]);
                    incEdges[s2[i2]]++; 
                    break;
                }
                i1++; i2++;
                if (i2 == s2.size() && i1 < s1.size()) return "";
            }
        }
        queue<char> noEdges;
        for (auto it : incEdges) {
            if (it.second == 0) noEdges.push(it.first);
        }
        
        string res;
        res.reserve(letters.size());
        
        char cur;
        while (!noEdges.empty()) {
            cur = noEdges.front();
            noEdges.pop();
            
            for (char& c : adjList[cur]) {
                if (--incEdges[c] == 0) noEdges.push(c);
            }
            res += cur;
        }
        if (res.size() != incEdges.size()) return "";
        return res;
        
        
    }
};