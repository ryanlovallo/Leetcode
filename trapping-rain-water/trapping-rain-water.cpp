class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = INT_MIN, rightmax = INT_MIN, left = 0, right = height.size()-1;
        
        int sum = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftmax) {
                    leftmax = height[left];
                } else {
                    sum += leftmax - height[left];
                }
                ++left;
            } else {
                if (height[right] > rightmax) {
                    rightmax = height[right];
                } else {
                    sum += rightmax - height[right];
                }
                --right;
            }
        }
        return sum;
    }
};
