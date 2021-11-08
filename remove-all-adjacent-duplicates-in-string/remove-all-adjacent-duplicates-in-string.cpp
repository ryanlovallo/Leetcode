class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (!st.empty() && c == st.top()) st.pop();
            else st.push(c);
        }
        string res;
        res.reserve(st.size());
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};