class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 1) return "";
        
        string s1, s2, maxStr = "";
        for(int i = 0 ; i < s.size() ; ++i) {
            s1 = maxSubstring(s, i, i);
            s2 = maxSubstring(s, i, i+1);
            string str = (s1.size()>s2.size()) ? s1 : s2;
            if(str.size() > maxStr.size()) {
                maxStr = str;
            }
        }
        return maxStr;
    }
    
    string maxSubstring(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left+1, (right-left-1));

    }
};