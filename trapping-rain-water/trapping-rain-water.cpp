class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, sum = 0;
        int leftmax = INT_MIN, rightmax = INT_MIN;
        
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] > leftmax) {
                    leftmax = height[l];
                } else {
                    sum += leftmax - height[l];
                }
                l++;
            } else {
                if (height[r] > rightmax) {
                    rightmax = height[r];
                } else {
                    sum += rightmax - height[r];
                }
                r--;
            }
        }
        return sum;
    }
};