class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int n1 = num1.size()-1, n2 = num2.size()-1, carry = 0, n;
        
        while (n1 >= 0 || n2 >= 0) {
            if (n1 < 0) {
                n = int(num2[n2] - '0') + carry;
                n2--;
            } else if (n2 < 0) {
                n = int(num1[n1] - '0') + carry;
                n1--;
            } else {
                n = int(num1[n1--] - '0') + int(num2[n2--] - '0') + carry;
            }
            res += char('0' + (n % 10));
            carry = n / 10;
        }
        if (carry > 0) res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};