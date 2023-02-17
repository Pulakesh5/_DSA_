long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        vector<long long> series(GeekNum.begin(), GeekNum.end());
        if(N<=K) return series[N-1];
        long long next=0;
        for(int i=0;i<K;i++)
            next+=series[i];
        for(int i=K;i<N;i++)
        {
            series.push_back(next);
            next+=next;
            next-=series[i-K];
        }
        return series.back();
    }
