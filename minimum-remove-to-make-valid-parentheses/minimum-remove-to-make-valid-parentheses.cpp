class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) continue;
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')' && st.empty()) {
                s[i] = '!';
            } else {
                st.pop();
            }
        }
        while (!st.empty()) {
            s[st.top()] = '!';
            st.pop();
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