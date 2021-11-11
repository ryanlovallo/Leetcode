class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, aint = a.size()-1, bint = b.size()-1;
        
        string res = "";
        while (aint >= 0 || bint >= 0 || carry) {
            carry += (aint >= 0) ? (a[aint--] - '0') : 0;
            carry += (bint >= 0) ? (b[bint--] - '0') : 0;
            
            res = char(carry%2 + '0') + res;
            carry /= 2;
        }
        return res;
    }
};