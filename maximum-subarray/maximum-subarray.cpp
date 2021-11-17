class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curSum = 0;
        for (int& n : nums) {
            curSum = max(curSum + n, n);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};