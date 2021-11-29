class Solution {
public:
    int minAddToMakeValid(string s) {
        int emptyRights = 0, numLefts = 0;
        
        for (char& c : s) {
            if (c == '(') numLefts++;
            else if (c == ')' && numLefts > 0) numLefts--;
            else emptyRights++;
        }
        return emptyRights + numLefts;
    }
};