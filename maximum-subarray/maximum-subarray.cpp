class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = INT_MIN;
        
        for (int& n : nums) {
            curSum = max(curSum + n, n);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};