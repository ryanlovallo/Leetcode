class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ana(26, 0);
        vector<int> letters(26,0);
        
        for (char c : p) ana[c - 'a']++;
        
        vector<int> res;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (right - left < p.size()-1)  {
                letters[s[right]-'a']++;
                continue;
            }
            
            letters[s[right]-'a']++;
            
            if (ana == letters) {
                res.push_back(left);
            }
            letters[s[left++]-'a']--;
        }
        return res;
    }
};

/*


*/