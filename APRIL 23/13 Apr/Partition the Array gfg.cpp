    vector<long long> search(vector<long long> &pre, int l, int r)
    {
        int lo=l, hi=r-1, mid;
        
        long long minSum=0, maxSum=pre[r]-pre[l-1], lsum , rsum;
        //cout<<l<<" "<<r<<" : "<<minSum<<" "<<maxSum<<endl;
        while(lo<=hi)
        {
            mid = lo+(hi-lo)/2;
            lsum = pre[mid]-pre[l-1];
            rsum = pre[r]-pre[mid];
            //cout<<lsum<<" "<<rsum<<endl;
            if(abs(rsum-lsum) < (maxSum-minSum))
            {
                //cout<<"reached \t";
                minSum = min(lsum,rsum);
                maxSum = max(lsum,rsum);
            }
            if(lsum<rsum) lo=mid+1;
            else
                hi=mid-1;
        }
        //cout<<"returning "<<minSum<<" "<<maxSum<<endl;
        vector<long long> ans={minSum,maxSum};
        return ans;
    }
    long long minDifference(int N, vector<int> &A) {
        // code here
        vector<long long> prefixSum(N+1,0);
        for(int i=1;i<=N;i++)
            prefixSum[i]=prefixSum[i-1]+A[i-1];
        int ll, lr, rl, rr;
        long long ans=prefixSum[N];
        for(int i=1;i<(N-2);i++)
        {
            ll=1;
            lr=i+1;
            rl=i+2;
            rr=N;
            vector<long long> ls = search(prefixSum,ll,lr);
            vector<long long> rs = search(prefixSum,rl,rr);
            //cout<<ls[0]<<" "<<ls[1]<<" "<<rs[0]<<" "<<rs[1]<<endl; 
            ans = min(ans, max(ls[1],rs[1]) - min(ls[0],rs[0]));
        }
        return ans;
    }
