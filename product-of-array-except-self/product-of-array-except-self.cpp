class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProd(nums.size(), 0), rightProd(nums.size(), 0);
        leftProd.front() = 1, rightProd.back() = 1;
        for (int i = 1; i < nums.size(); ++i) {
            leftProd[i] = leftProd[i-1] * nums[i-1];
            rightProd[nums.size()-1 - i] = rightProd[nums.size() - i] * nums[nums.size() - i];
        }
        vector<int> res;
        res.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res.push_back(leftProd[i] * rightProd[i]);
        }
        return res;
    }
};