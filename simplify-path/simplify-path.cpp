class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        stack<string> st;
        string cur;
        
        while(getline(ss, cur, '/')) {
            if (cur == "" || cur == ".") continue;
            
            if (cur == ".." && !st.empty()) st.pop();
            else if (cur != "..") st.push(cur);
        }
        
        if (st.empty()) return "/";
        
        string res = "";
        vector<string> v;
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        
        for (int i = v.size()-1; i>=0; --i) {
            res += "/" + v[i];
        }
        return res;
    }
};