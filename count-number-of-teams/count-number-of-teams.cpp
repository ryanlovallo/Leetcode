class Solution {
public:
    int numTeams(vector<int>& rating) {
        unordered_map<int,int> lower, higher;
        
        for (int i = 0; i < rating.size(); ++i) {
            for (int j = i+1; j < rating.size(); ++j) {
                if (rating[i] < rating[j])
                    higher[i]++;
                else
                    lower[i]++;
            }
        }
        int total = 0;
        for (int i = 0; i < rating.size(); ++i) {
            for (int j = i+1; j < rating.size(); ++j) {
                if (rating[i] < rating[j])
                    total += higher[j];
                else
                    total += lower[j];
            }
        }
        return total;
    }
};