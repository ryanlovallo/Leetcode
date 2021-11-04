class Solution {
public:
    int minAddToMakeValid(string s) {
        int lefts = 0, stack = 0;
        
        for (char c : s) {
            if (c == '(') stack++;
            else if (c == ')' && stack == 0) lefts++;
            else stack--;
        }
        return lefts + stack;
    }
};