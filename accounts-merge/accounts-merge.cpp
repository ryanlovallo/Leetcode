class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjList;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        // build graph
        
        for (vector<string>& acct : accounts) {
            string name = acct[0];
            string firstEmail = acct[1];
            
            for (int i = 2; i < acct.size(); ++i) {
                adjList[firstEmail].push_back(acct[i]);
                adjList[acct[i]].push_back(firstEmail);
            }
        }
        
        vector<vector<string>> res;
        
        for (vector<string>& acct : accounts) {
            string name = acct[0];
            string firstEmail = acct[1];
            
            for (int i = 1; i < acct.size(); ++i) {
                string curEmail = acct[i];
                if (visited.find(curEmail) != visited.end()) continue;
                
                // new componenet
                vector<string> newAccount;
                newAccount.push_back(name);
                dfs(accounts, newAccount, curEmail);
                
                sort(newAccount.begin()+1, newAccount.end());
                res.push_back(newAccount);
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<string>>& accounts, vector<string>& curAccount, string email) {
        visited.insert(email);
        
        curAccount.push_back(email);
        
        for (string& nextEmail : adjList[email]) {
            if (visited.find(nextEmail) != visited.end()) continue;
            dfs(accounts, curAccount, nextEmail);
        }
    }
};










