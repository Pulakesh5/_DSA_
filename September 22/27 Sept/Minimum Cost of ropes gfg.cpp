long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr,arr+n);
        long long cost=0,item1,item2;
        while(pq.size()>1)
        {
            item1=pq.top();
            pq.pop();
            item2=pq.top();
            pq.pop();
            cost+=(item1+item2);
            pq.push((item1+item2));
        }
        return cost;
    }
