class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> indexes;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) continue;
            if (s[i] == '(') indexes.push(i);
            else if (indexes.empty()) s[i] = '!';
            else indexes.pop();
        } 
        while (!indexes.empty()) {
            s[indexes.top()] = '!';
            indexes.pop();
        }
        
        string res;
        s.reserve(s.size());
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i]) == '!') continue;
            res += s[i];
        }

        return res;
    }
};