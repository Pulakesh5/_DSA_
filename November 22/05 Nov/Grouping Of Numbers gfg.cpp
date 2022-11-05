   int maxGroupSize(int arr[], int N, int K) {
        // code here
        map<int,int> count;
        
        for(int i=0;i<N;i++)
        {
            count[arr[i]%K]++;
        }
        
        int maxGroupSize=0;
        
        for(int i=1;i<(K+1)/2;i++)
        {
            maxGroupSize+=max(count[i],count[K-i]);
        }
        
        if(count[0]>0) maxGroupSize++;
        if(K%2==0 && count[K/2]>0) maxGroupSize++;
        
        return maxGroupSize;
    }
