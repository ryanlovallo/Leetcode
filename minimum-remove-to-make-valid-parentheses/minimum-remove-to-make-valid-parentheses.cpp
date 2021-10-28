class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                if (stk.size()) {
                    stk.pop();
                } else {
                    s[i] = '*';
                }
            }
        }
        while (!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == '*') s.erase(i,1);
        }
        return s;
    }
};