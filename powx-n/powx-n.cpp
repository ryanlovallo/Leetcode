class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double num = p(x,abs(n));
        return (n < 0) ? 1/num : num;
    }
    
    double p(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        
        double num = myPow(x,n/2);
        if (n % 2 == 0) {
            return num * num;
        } else {
            return num * num * x;
        }
    }
};