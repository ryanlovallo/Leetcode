class Solution {
public:
    int minAddToMakeValid(string s) {
        int numLeft = 0;
        int numRight = 0;
        for (char &c : s) { 
            if (c == '(') {
                numLeft++;
            } else {
                if (numLeft == 0) {
                    numRight++;
                } else {
                    numLeft--;
                }
            }
        }
        return numRight + numLeft;
    }
};