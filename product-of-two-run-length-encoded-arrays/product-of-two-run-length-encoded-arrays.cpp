class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>>ans;
        int prevMultiple=0;
        int i1=0;
        int i2=0;
        while(i1<encoded1.size() && i2<encoded2.size()){
            int cnt1=encoded1[i1][1];
            int cnt2=encoded2[i2][1];
            int mincnt=min(cnt1, cnt2);
            int product=encoded1[i1][0]*encoded2[i2][0];
            if(prevMultiple==product && ans.size()>0){
                ans[ans.size()-1][1]+=mincnt;
            }
            else{
                ans.push_back({product, mincnt});
            }
            prevMultiple = product;
            encoded1[i1][1]-=mincnt;
            encoded2[i2][1]-=mincnt;
            if(!encoded1[i1][1]) i1++;
            if(!encoded2[i2][1]) i2++;
        }
        return ans;
    }
};