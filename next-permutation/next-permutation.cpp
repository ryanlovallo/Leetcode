class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1) return;
        
        int peakIndex = -1;
        for (int i = nums.size()-1; i > 0; --i) {
            if (nums[i] > nums[i-1]) {
                peakIndex = i-1;
                break;
            }
        }
        
        if (peakIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int swapIndex = -1;
        for (int i = peakIndex+1; i < nums.size(); ++i) {
            if (nums[i] <= nums[peakIndex]) {
                swapIndex = i-1;
                break;
            }
        }
        if (swapIndex == -1) swapIndex = nums.size()-1;
        
        swap(nums[peakIndex], nums[swapIndex]);
        reverse(nums.begin() + peakIndex + 1, nums.end());
        
    }
};

// 1 3 5 3 2
