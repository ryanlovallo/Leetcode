class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int runner = 1, cur = nums[0]+1, ans = nums[0];
        
        for (int i = 0; i < k; ++i) {
            if (runner < nums.size()) {
                while (nums[runner] == cur) {
                    runner++; cur++;
                }
            } 
            
            ans = cur;
            cur++;
        }
        return ans;
    }
};