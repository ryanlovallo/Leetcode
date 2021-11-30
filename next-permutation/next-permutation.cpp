class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        int rev;
        for (int i = nums.size()-1; i > 0; --i) {
            if (nums[i] <= nums[i-1]) continue;
            
            int indx = i;
            
            while (indx < nums.size()) {
                if (nums[indx] <= nums[i-1]) break;
                indx++;
            } 
            indx--; 
            
            swap (nums[i-1], nums[indx]);
            rev = i;
            break;
        }
        
        reverse(nums.begin() + rev, nums.end());
    }
};

/*
5 2 6 4 3

5 3 2 4 6
*/
