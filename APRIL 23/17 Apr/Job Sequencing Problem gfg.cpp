    vector<int> JobScheduling(Job arr[], int n) 
    {
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[arr[i].dead].push_back(arr[i].profit);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto it:mp)
        {
            int date = it.first;
            vector<int> list = it.second;
            for(int job:list)
            {
                pq.push(job);
                if(pq.size()>date) pq.pop();
            }
        }
        vector<int> ans(2,0);
        ans[0]=pq.size();
        
        while(!pq.empty())
        {
            ans[1]+=pq.top();
            pq.pop();
        }
        return ans;
    } 
