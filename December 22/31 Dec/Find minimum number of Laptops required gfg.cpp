    int minLaptops(int N, int start[], int end[]) {
        // Code here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        vector<pair<int,int>> vp;
        
        for(int i=0;i<N;i++)
            vp.push_back({start[i], end[i]});
        
        sort(vp.begin(), vp.end());
        int laptops=0;
        
        for(int i=0;i<N;i++)
        {
            if(pq.size()!=0 && vp[i].first>=pq.top())
                pq.pop();
            else
                laptops++;
                
            pq.push(vp[i].second);
        }
        
        return laptops;
    }
