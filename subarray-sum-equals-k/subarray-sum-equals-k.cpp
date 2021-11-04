class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        counts[0] = 1;
        int res = 0, sum = 0;
        
        for (int n : nums) {
            sum += n;
            
            res += counts[sum - k];
            
            counts[sum]++;
        }
        return res;
    }
};