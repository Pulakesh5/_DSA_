    vector<int> match;
    vector<int> visited;
    bool solve(int i, vector<vector<int>> &G)
    {
        int J=G[0].size();
        
        for(int j=0;j<J;j++)
        {
            if(G[i][j] && !visited[j])
            {
                visited[j]=1;
                if(match[j]==-1 || solve(match[j],G))
                {
                    match[j]=i;
                    return true;
                }
            }
        }
        return false;
    }
	int maximumMatch(vector<vector<int>>&G){
	    // Code here
	    int p = G.size();
	    int j = G[0].size();
	    
	    match = vector<int>(j,-1);
	    int result=0;
	    
	    for(int i=0;i<p;i++)
	    {
	        visited = vector<int> (j,0);
	        if(solve(i,G))
	            result++;
	    }
	    
	    return result;
	}
