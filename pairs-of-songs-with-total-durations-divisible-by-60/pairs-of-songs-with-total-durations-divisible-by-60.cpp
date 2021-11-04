class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> counts(61,0);
        int res = 0;
        for (int i = 0; i < time.size(); ++i) {
            if (time[i] % 60 == 0) 
                res += counts[0];
            else 
                res += counts[60 - time[i] % 60];
            
            counts[time[i] % 60]++;
        }
        return res;
    }
};