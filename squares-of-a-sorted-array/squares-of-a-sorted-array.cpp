class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        
        int l = 0, r = nums.size()-1;
        for (int i = nums.size()-1; i >= 0; --i) {
            res[i] = (abs(nums[r]) > abs(nums[l])) ? pow(nums[r--],2) : pow(nums[l++],2);
        }
        return res;
    }
    
};