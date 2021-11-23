class Solution {
public:
    string customSortString(string order, string s) {
        string res;
        res.reserve(s.size());
        unordered_map<char, int> counts;
        
        for (char& c : s) counts[c]++;
        
        for (char &c : order) {
            if (counts.find(c) != counts.end()) {
                for (int i = 0; i < counts[c]; ++i) {
                    res += c;
                }
                counts.erase(c);
            }
        }
        
        for (auto it : counts) {
            for (int i = 0; i < it.second; ++i) {
                res += it.first;
            }
        }
        return res;
    }
};