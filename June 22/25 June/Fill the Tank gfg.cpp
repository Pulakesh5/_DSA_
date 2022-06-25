class Solution {

public:
    long long limit=1e18;
    bool visited[100002];
    long long DFS(vector<int> adj[],int *Cap, int source, int parent){
        long long total_req=0,child_req=0,max_req=0,child_count=0;
        visited[source]=true;
        for(auto child:adj[source]){
            if(!visited[child]){
                child_count++;
                child_req=DFS(adj,Cap,child,source);
                if(child_req==-1) return -1;
                max_req=max(max_req,child_req);
            }
        }
        total_req = child_count*max_req + Cap[source-1];
        if(total_req > limit) return -1;
        return total_req;
    }
    long long minimum_amount(vector<vector<int>> &Edges, int N, int source, int *Cap){
       // Code here
       vector<int> adj[N+1];
       memset(visited,false,100002);
       for(auto &edge:Edges){
           adj[edge[0]].push_back(edge[1]);
           adj[edge[1]].push_back(edge[0]);
       }
       long long ans=DFS(adj,Cap,source,1);
       //if(!possible) return -1;
       return ans;
    }
};
