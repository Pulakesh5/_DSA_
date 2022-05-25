class Solution {
public:
    static bool comp(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first==p2.first)
            return p1.second>p2.second;
        return p1.first<p2.first;
    } 
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        vector<pair<int,int>> vp(n);
        
        for(int i=0;i<n;i++)
            vp[i]={env[i][0],env[i][1]};
        
        sort(begin(vp),end(vp), comp);

        vector<int> dp;
        for(int i=0;i<n;i++){
            auto itr=lower_bound(dp.begin(), dp.end(),vp[i].second);
            if(itr==dp.end())
                dp.push_back(vp[i].second);
            else
                *itr=vp[i].second;
        }
        return dp.size();
    }
};
