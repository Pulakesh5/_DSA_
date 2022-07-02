class Solution {
public:
    vector<int> adj[20];
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    for(auto it:edges){
	        adj[it[0]].push_back(it[1]);
	    }
	    return dfs(s,d);
	}
	
	int dfs(int src, int dst){
	    if(src==dst) return 1;
	    int ans=0;
	    for(auto it:adj[src]){
	        ans+=dfs(it,dst);
	    }
	    return ans;
	}
};
