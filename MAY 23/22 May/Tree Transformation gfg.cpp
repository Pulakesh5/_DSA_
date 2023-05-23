    int solve(int N, vector<int> p){
        // code here
        int edgeRemoved = N-1;
        vector<int> degree(N,0);
        for(int i=1; i<N; i++)
        {
            degree[i]++;
            degree[p[i]]++;
        }
        for(int i=0; i<N; i++)
            if(degree[i]==1)
                edgeRemoved--;
        return max(0, edgeRemoved);
        
    }
