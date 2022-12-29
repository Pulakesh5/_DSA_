class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        using pp = pair<int,pair<int,int>>;

        priority_queue<pp, vector<pp>, greater<pp> > pq;
        vector<pp> vp;
        int n=tasks.size();

        for(int i=0;i<n;i++)
            vp.push_back({tasks[i][0],{tasks[i][1],i}});
        sort(vp.begin(),vp.end());

        int i=0;
        long long currTime=vp[0].first;
        vector<int> ans;

        while(i<n || !pq.empty())
        {
            while(i<n && currTime>=vp[i].first)
            {
                pq.push({vp[i].second.first,{vp[i].second.second,vp[i].first}});
                i++;
            }
            pp top=pq.top();
            pq.pop();
            currTime+=top.first;
            ans.push_back(top.second.first);

            if(i<n && currTime<vp[i].first && pq.empty())
                currTime=vp[i].first;
        }
        return ans;

    }
};
