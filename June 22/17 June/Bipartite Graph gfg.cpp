class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    bool ans=true;
	    
	    for(int i=0;i<V && ans;i++){
	        if(color[i]!=-1) continue;
	        ans = BFS(adj,color,i);
	    }
	    return ans;
	    
	}
	
	bool BFS(vector<int> adj[],vector<int> &color, int source){
	    queue<int> q;
	    q.push(source);
	    color[source]=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        for(auto ng:adj[node]){
	            if(ng==node)
	                return false;
	            else if(color[ng]==-1)
	            {
	                color[ng]=1-color[node];
	                q.push(ng);
	            }
	            else if(color[ng]==color[node])
	                return false;
	        }
	    }
	    
	    return true;
	}

};
