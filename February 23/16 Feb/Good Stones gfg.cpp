    bool check(vector<int> &dp, vector<bool> &visited, vector<int> &arr, int i)
    {
        if(i>=arr.size()) return true;
        
        if(visited[i]==1) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        visited[i] = true;
        
        dp[i] = check(dp, visited, arr, i+arr[i]);
        
        visited[i] = false;
        
        return dp[i];
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> parent(n,-1), dp(n,-1);
        vector<bool> visited(n,false);
        int goodStone=0;
        for(int i=0;i<n;i++)
        {
            if(check(dp, visited, arr, i))
                goodStone++;
        }
        return goodStone;
    }  
