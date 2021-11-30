class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1,-1};
        int l = 0, r = nums.size()-1, mid;
        // find first
        while (l < r) { 
            mid = l + (r-l)/2;
            
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (nums[l] != target) return {-1,-1};
        int left = l;
        
        r = nums.size()-1;
        while (l < r) {
            mid = l + (r-l)/2 + 1;
            
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return {left, l};
        
        
    }
};