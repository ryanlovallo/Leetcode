class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int sum = 0, res = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            
            res += counts[sum - k];
            counts[sum]++;
        }
        return res;
    }
};