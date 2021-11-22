class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for (int& n : weights) sum += n;
        
        if (days == 1) return sum;
        
        int left = sum/days, right = sum, mid;
        
        while (left < right) {
            mid = left + (right-left)/2;
            
            if (checkWeight(weights, days, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    bool checkWeight(vector<int>& weights, int days, int weight) {
        int index = 0, curSum;
        for (int i = 0; i < days; ++i) {
            curSum = 0;
            
            while (index < weights.size() && curSum + weights[index] <= weight) {
                curSum += weights[index++];
            }
            
            if (index >= weights.size()) return true;
            
        }
        return false;
    }
};
