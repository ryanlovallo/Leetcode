class Solution {
public:
    vector<string> letters = {"","","abc", "def", "ghi","jkl","mno",
                                    "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        return dfs(digits);
    }
    
    vector<string> dfs(string cur) {
        
        if (cur == "") {
            return {""};
        }
        
        vector<string> strs = dfs(cur.substr(1));
        vector<string> res;
        for (char c : letters[cur[0]-'0']) {
            for (string s : strs) {
                res.push_back(c + s);
            }
        }
        return res;
    }
};