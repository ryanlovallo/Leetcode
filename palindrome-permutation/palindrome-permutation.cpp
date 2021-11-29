class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> counts(26);
        
        for (char& c : s) {
            counts[c - 'a']++;
        }
        
        bool seenOdd = false;
        for (int& n : counts) {
            if (n%2 != 0) {
                if (seenOdd) return false;
                seenOdd = true;
            }
        }
        return true;
    }
};