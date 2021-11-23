class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, maxDist = -1;
        int numZeros = 0;
        for(; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                if (numZeros == k) {
                    maxDist = max(r-l, maxDist);
                    while(nums[l] == 1) l++;
                    l++;
                } else {
                    numZeros++;
                }
            }
        }
        
        return max(maxDist, r-l);
    }
};