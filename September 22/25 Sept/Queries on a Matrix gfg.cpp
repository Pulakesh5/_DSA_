    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        // Code here
        vector<vector<int>> v(n,vector<int>(n+1,0));
        for(auto x : Queries)
        {
            for(int i = x[0];i<=x[2];i++)
            {
                v[i][x[1]] +=1;
                v[i][x[3]+1] -=1;
            }
        }
        for(int i = 0;i<n;i++)
            for(int j = 1;j<n+1;j++)
                v[i][j] +=v[i][j-1];

        for(int i = 0;i<n;i++)
            v[i].pop_back();
        
        return v;
    }
