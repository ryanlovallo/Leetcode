class SparseVector {
public:
    
    unordered_map<int,int> val;     // index --> value
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            val[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int prod = 0;
        for (auto it : val) {
            if (vec.val.find(it.first) != vec.val.end()) {
                prod += it.second * vec.val[it.first];
            }
        }
        return prod;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);