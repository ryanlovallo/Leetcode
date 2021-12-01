class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size()-1, mid;
        
        while (left < right) {
            mid = partition(points, left, right);
            
            if (mid == k) break;
            else if (mid < k) left = mid + 1;
            else right = mid - 1;
        }
        
        points.resize(k);
        return points;
        
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int p = left;
        int dis = dist(points[right]);
        
        for (; left < right; ++left) {
            if (dist(points[left]) <= dis) {
                swap(points[p++], points[left]);
            }
        }
        swap(points[p], points[right]);
        return p;
    }
    
    int dist(vector<int> v) {
        return v[0]*v[0] + v[1]*v[1];
    }
};