class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        vector<int> res;
        res.reserve(nums.size());
        for (int& n : nums) {
            if (counts.find(n) == counts.end()) res.push_back(n);
            counts[n]++;
        }
        
        nth_element(res.begin(), res.begin()+k, res.end(), [&counts](int& a, int& b) {
            return (counts[a] > counts[b]);
        });
        res.resize(k);
        return res;
        
    }
};

/*

time complexity: amortized O(n)
space: O(n)

*/