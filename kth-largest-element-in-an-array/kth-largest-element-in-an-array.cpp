class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        int index;
        while (left <= right) {
            index = partition(nums, left, right);
            
            if (index == nums.size() - k) {
                return nums[index];
            }
            
            if (index > nums.size() - k) {
                right = index - 1;
            } else {
                left = index + 1;
            }
        }
        return nums[index];
        
    }
    
    int partition(vector<int>& nums, int start, int end) {
        if (end <= start) {
            return start;
        }
        
        int pivot = start, target = nums[end];
        
        for (int i = start; i < end; ++i) {
            if (nums[i] < target) {
                swap(nums[pivot], nums[i]);
                ++pivot;
            }
        }
        swap(nums[pivot], nums[end]);
        return pivot;
    }
};