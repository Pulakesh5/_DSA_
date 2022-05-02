
//Use BFS for each node to get max distance to farthest node
class Solution{
public:
    int partyHouse(int n, vector<vector<int>> &adj){
        
        vector<int> visited(n+1,false);
        int ans=INT_MAX;
        
        for(int i=1;i<=n;i++){
            
            queue<int> q;
            visited[i]=true;
            q.push(i);
            int dis=0;
            
            while(!q.empty()){
            
                int size=q.size();
                dis++;
            
                for(int i=0;i<size;i++){  
            
                    int curr=q.front();
                    q.pop();
            
                    for(auto it:adj[curr]){
                         if(visited[it]) continue;
                         visited[it]=true;
                         q.push(it);
                    }
                }
            }
            ans=min(ans,dis-1);
            fill(visited.begin(), visited.end(), false);
        }
        
        return ans;
        
    }
};
