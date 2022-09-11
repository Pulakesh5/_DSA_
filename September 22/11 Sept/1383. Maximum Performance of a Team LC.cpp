class Solution {
public:
    int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++)
        {
            vp[i]={efficiency[i],speed[i]};
        }
        
        sort(vp.rbegin(),vp.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long speedSum=0,performance=0;
        for(int i=0;i<n;i++)
        {
            pq.emplace(vp[i].second);
            speedSum+=vp[i].second;
            if(pq.size()>k)
            {
                speedSum-=pq.top();
                pq.pop();
            }
            performance=max(performance,(1ll*speedSum*(vp[i].first)));
        }
        return performance%mod;
    }
};
