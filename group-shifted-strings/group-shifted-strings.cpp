class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> shifts;
        
        for (string& s : strings) {
            if (s.size() == 1) {
                shifts[""].push_back(s);
                continue;
            }
            
            string res = "";
            int cur;
            for (int i = 0; i < s.size()-1; ++i) {
                cur = s[i+1] - s[i];
                if (cur < 0) cur += 26;
                
                res += to_string(cur) + ",";
            }
            shifts[res].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it : shifts) {
            res.push_back(it.second);
        }
        return res;
    }
    
    // space = O(n)
    // time = O(n*k) , n = # strings, k = size of string
};
