class SparseVector {
public:
    
    unordered_map<int,int> m;
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                m[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for (auto it = vec.m.begin(); it != vec.m.end(); ++it) {
            if (this->m.find(it->first) != this->m.end()) {
                sum += it->second * this->m[it->first];
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);