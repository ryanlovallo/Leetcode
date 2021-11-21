class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (string& s : strs) {
            vector<int> arr(26);
            for (char& c : s) arr[c - 'a']++;
            string res;
            for (int& n : arr) {
                res += "." + to_string(n);
            }
            mp[res].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};