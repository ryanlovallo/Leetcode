class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0, r = points.size()-1, pivot;
        while (l < r) {
            pivot = partition(points, l, r);
            
            if (pivot == k) break;
            else if (pivot > k) {
                r = pivot-1;
            } else {
                l = pivot+1;
            }
        }
        points.resize(k);
        return points;
    }
    
    int dist(vector<int> point) {
        return point[0]*point[0] + point[1]*point[1];
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int p = left;
        int distPivot = dist(points[right]);
        
        for (; left < right; ++left) {
            if (dist(points[left]) < distPivot) {
                swap(points[p], points[left]);
                ++p;
            }
        }
        swap(points[p], points[right]);
        return p;
    }
};