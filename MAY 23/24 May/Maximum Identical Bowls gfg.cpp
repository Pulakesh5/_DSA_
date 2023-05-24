    int getMaximum(int N, vector<int> &arr) {
        // code here
        long long sum = 0;
        for(int i=0; i<N; i++)
            sum = sum + arr[i];
        for(int bowls=N; bowls>0; bowls--)
            if(sum%bowls == 0)
                return bowls;
        return -1;
    }
