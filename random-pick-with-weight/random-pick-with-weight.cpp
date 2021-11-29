class Solution {
public:
    
    vector<int> sums;
    
    Solution(vector<int>& w) {
        int sum = 0;
        sums.resize(w.size());
        for (int i = 0; i < w.size(); ++i) {
            sum += w[i];
            sums[i] = sum;
        }
    }
    
    int pickIndex() {
        int rando = rand() % sums.back();
        
        for (int i = 0; i < sums.size(); ++i) {
            if (rando < sums[i]) return i;
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */