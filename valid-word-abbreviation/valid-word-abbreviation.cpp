class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int index = 0, i = 0;
        while (index < word.size() && i < abbr.size()) {
            if (isdigit(abbr[i])) {
                if (abbr[i] == '0') return false;
                int digit = 0;
                while (isdigit(abbr[i])) {
                    digit = digit*10 + int(abbr[i]-'0');
                    ++i;
                }
                index += digit;
            } else {
                if (word[index++] != abbr[i++]) return false;
            }
        }
        return (index == word.size() && i == abbr.size());
    }
};