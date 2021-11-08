class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int currentNum = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            }
            
            if (!isdigit(c) && c != ' ' || i == s.size()-1) {
                if (sign == '+') st.push(currentNum);
                else if (sign == '-') st.push(-1 * currentNum);
                else {
                    int tp = st.top();
                    st.pop();
                    if (sign == '*') st.push(tp * currentNum);
                    else st.push(tp / currentNum);
                }
                sign = c;
                currentNum = 0;
            }
        
        }
        
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};