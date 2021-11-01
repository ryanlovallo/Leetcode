class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        for (int &n : w) {
            if (prefixSum.empty()) {
                prefixSum.push_back(n);
            } else {
                prefixSum.push_back(prefixSum.back() + n);
            }
        }
    }
    
    int pickIndex() {
        int r = rand() % prefixSum.back();
        
        for (int i = 0; i < prefixSum.size(); ++i) {
            if (r < prefixSum[i]) {
                return i;
            }
        }
        return prefixSum.size()-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */