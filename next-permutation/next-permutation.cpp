class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        
        int rev = 0;
        for (int i = nums.size()-1; i >= 1; --i) {
            if (nums[i] <= nums[i-1]) continue;
            
            int indx = i;
            while (indx < nums.size()) {
                if (nums[indx] <= nums[i-1]) {
                    break;
                }
                indx++;
            }
            indx--;
            swap(nums[indx], nums[i-1]);
            rev = i;
            break;
        } 
        
        reverse(nums.begin() + rev, nums.end());
    }
};

// 2 3 1

// 2 7 2 5