class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0, r = points.size()-1, mid;
        
        while (l < r) {
            mid = partition(points, l, r);
            
            if (mid == k) {
                break;    
            }
            if (mid >= k) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        points.resize(k);
        return points;
        
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        if (left >= right ) return left;
        int p = left;
        int pointDist = dist(points[right][0], points[right][1]);
        
        for (int i = left; i < right; ++i) {
            if (dist(points[i][0], points[i][1]) < pointDist) {
                swap(points[p], points[i]);
                p++;
            } 
        }
        swap(points[right], points[p]);
        return p;
    }
    
    int dist(int x, int y) {
        return x*x + y*y;
    }
    
    
};