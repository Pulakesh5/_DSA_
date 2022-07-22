class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> adj_list(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)
            {
                //if(i==j) continue;
                if(adj[i][j]==1)
                    adj_list[i].push_back(j);
            }
        }
        int province=0;
        bool visited[V];
        memset(visited,false,V);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int vertice=q.front();
                    q.pop();
                    visited[vertice] = true;
                    for(auto it:adj_list[vertice]){
                        if(!visited[it]){
                            q.push(it);
                        }
                    }
                }
                province++;
            }
        }
        return province;
        
    }
};
/*********************************************************************************/
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int province=0;
        
        for(int i=0;i<V;i++){
            if(adj[i][i]==1){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    adj[v][v]=-1;
                    for(int j=0;j<V;j++){
                        if(adj[v][j]==1 && adj[j][j]!=-1){
                            q.push(j);
                        }
                    }
                }
                province++;
            }
        }
        
        return province;
    }
};

