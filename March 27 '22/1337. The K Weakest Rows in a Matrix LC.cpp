class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> pr;
        int i=0;
        for(auto &it:mat){
            int sum=0;
           
            pr.push_back({ accumulate(it.begin(),it.end(),sum),i++});
        }
        
        sort(pr.begin(),pr.end());
        vector<int> ans;
       for(int i=0;i<k;i++)
           ans.push_back(pr[i].second);
        return ans;
    }
};
