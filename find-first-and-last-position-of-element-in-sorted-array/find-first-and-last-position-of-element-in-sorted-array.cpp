class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1,-1};
        int l = 0, r = nums.size()-1, mid;
        
        while (l < r) {
            mid = l + (r-l)/2;
            
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if (nums[l] != target) return {-1,-1};
        int first = l;
        
        l = 0, r = nums.size()-1;
        
        while (l < r) {
            mid = l + (r-l+1)/2;
            
            if (nums[mid] <= target) l = mid;
            else r = mid-1;
        }
        
        return {first, r};
    }
};