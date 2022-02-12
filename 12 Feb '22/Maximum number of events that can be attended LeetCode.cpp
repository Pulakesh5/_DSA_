class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        pair<int,int> meet[n];
        for(int i=0;i<n;i++)
        {
            meet[i].first=events[i][0];
            meet[i].second=events[i][1];
        }
        sort(meet,meet+n);
        
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0,i=0;
        for(int d=1;d<=100000;d++){
            while(pq.size() && pq.top()<d)
                pq.pop();
            while(i<n && meet[i].first==d)
                pq.push(meet[i++].second);
            if(pq.size()>0)
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};
