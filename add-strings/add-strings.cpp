class Solution {
public:
    string addStrings(string num1, string num2) {
        int i1 = num1.size()-1, i2 = num2.size()-1, carry = 0, cur;
        string res;
        
        while (i1 >= 0 || i2 >= 0) {
            if (i1 < 0) {
                cur = ((num2[i2] - '0') + carry) % 10;
                carry = ((num2[i2--] - '0') + carry) / 10;
            } else if (i2 < 0) {
                cur = ((num1[i1] - '0') + carry) % 10;
                carry = ((num1[i1--] - '0') + carry) / 10;
            } else {
                int c = (num1[i1--] - '0') + (num2[i2--] - '0') + carry;
                cur = c % 10;
                carry = c / 10;
            }
            res += to_string(cur);
        }
        if (carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
        // reverse
    }
};

// 4 5 6
//   7 7

// 3 