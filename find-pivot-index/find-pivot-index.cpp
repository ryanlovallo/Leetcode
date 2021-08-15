class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        unordered_map<int,int> tb;
        for (int i = 0; i < nums.size(); ++i) {
            tb[i] = total;
            total += nums[i];
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (tb[i] == total - tb[i] - nums[i]) {
                return i;
            }
        }
        return -1;
    }
};