class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1, target = nums.size()-k, index;
        
        while (l < r) {
            index = partition(nums, l, r);
            if (index > target) {
                r = index-1;
            } else {
                l = index;
            }
        }
        return nums[l];
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int p = left, target = nums[right];
        
        for (int i = left; i < right; ++i) {
            if (nums[i] <= target) {
                swap(nums[i], nums[p]);
                p++;
            } 
        }
        swap(nums[p], nums[right]);
        return p;
    }
};