class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> counts;
        
        for (string& s : strings) {
            if (s.size() == 1) {
                counts[""].push_back(s);
                continue;
            }
            string key = "";
            int shift;
            for (int i = 0; i < s.size()-1; ++i) {
                shift = s[i+1] - s[i];
                if (shift < 0) shift += 26;
                key += to_string(shift) + ", ";
            }
            counts[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto it : counts) {
            result.push_back(it.second);
            sort(result.back().begin(), result.back().end());
        }
        return result;
    }
};

/*
Time complexity: O(N * klogk), N = number input strings, k = length of strings
Space complexity: O(N * k) 
*/