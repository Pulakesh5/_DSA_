//levelwise topological sorting or simply levelwise BFS

class Solution{
public:
    int minColour(int n, int m, vector<int> mat[]) {
        // code here
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        for(int i=0;i<m; i++){
            adj[mat[i][1]].push_back(mat[i][0]);
            indegree[mat[i][0]]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
            
        int level=0;
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){    
                int front=q.front();
                q.pop();
                for(auto v:adj[front]){
                    indegree[v]--;
                    if(indegree[v]==0)
                        q.push(v);
                }
            }
            level++;
        }
        return level;
                
    }
};
