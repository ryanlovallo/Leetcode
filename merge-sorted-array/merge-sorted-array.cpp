class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        --m;
        --n;
        
        while (m >= 0 || n >= 0) {
            if (m < 0) {
                while (n >= 0) nums1[index--] = nums2[n--];
            } else if (n < 0) {
                    // check if you actually need this part, don't think you do
                break;
            }
            else {
                nums1[index] = (nums1[m] <= nums2[n]) ? nums2[n--] : nums1[m--];
                index--;
            }
        }
    }
};