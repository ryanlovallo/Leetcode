class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, total = 0;
        unordered_map<int,int> tb;
        tb[0] = 1;
        
        for (auto &n : nums) {
            total += n;
            result += tb[total-k]; 
            tb[total]++;
        }
        return result;
    }
};