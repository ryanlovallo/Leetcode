class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, curMin = INT_MAX;
        for (int &n : prices) {
            curMin = min(n, curMin);
            profit = max (profit, n - curMin);
        }
        return profit;
    }
};