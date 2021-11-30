class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> rems;    // remainder --> index
        rems[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int rem = sum % k;
            
            if (rems.find(rem) == rems.end()) {
                rems[rem] = i;
            } else if (i - rems[rem] > 1) return true;
        }
        return false;
    }
};