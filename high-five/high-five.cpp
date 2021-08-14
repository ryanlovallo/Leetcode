class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        sort(items.begin(), items.end());
        vector<vector<int>> res;
        
        unsigned int i = 0;
        while (i < items.size()) {
            int total = 0;
            queue<int> q;
            int cur_id = items[i][0];
            while (i < items.size() && items[i][0] == cur_id) {
                if (q.size() == 5) {
                    total -= q.front();
                    q.pop();
                }
                q.push(items[i][1]);
                total += items[i][1];
                ++i;
            }
            int avg = (int)(total / (int)q.size());
            res.push_back({cur_id, avg});
        }
        return res;
        
    }
};

/*
1. sort vec 
2. loop thru for each id
3. 
*/