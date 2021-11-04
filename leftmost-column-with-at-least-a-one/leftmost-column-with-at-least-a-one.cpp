/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int r = 0, c = dim[1]-1, val, smallestCol = INT_MAX;

        while (r < dim[0] && c >= 0) {
            val = binaryMatrix.get(r,c);
            if (val == 0) {
                r+=1;
            } else {
                smallestCol = c;
                c -= 1;
            }
        }
        return (smallestCol == INT_MAX) ? -1 : smallestCol;
    }
};