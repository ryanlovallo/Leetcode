class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
        find pivot point
        2 pointer, compare abs values,
        */
        if (nums[0] >= 0 || nums.back() < 0) {
            bool revr = nums.back() < 0;
            for(int &n : nums) n *= n;
            if (revr) reverse(nums.begin(), nums.end());
            return nums;
        }
        
        // pivot
        vector<int> res;
        res.reserve(nums.size());
        
        // find pivot
        int lpivot, rpivot;
        for(int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] < 0 && nums[i+1] >= 0) {
                lpivot = i;
                break;
            }
        }
        rpivot = lpivot+1;
        while (lpivot >= 0 || rpivot < nums.size()) {
            if (lpivot < 0) res.push_back(pow(nums[rpivot++],2));
            else if (rpivot >= nums.size()) res.push_back(pow(nums[lpivot--],2));
            else {
                if (abs(nums[lpivot]) >= abs(nums[rpivot])) res.push_back(pow(nums[rpivot++],2));
                else res.push_back(pow(nums[lpivot--],2)); 
            }
        }
        return res;
        
    }
};