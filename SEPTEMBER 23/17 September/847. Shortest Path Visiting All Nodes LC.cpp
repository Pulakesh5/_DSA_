class Solution {
public:
    class tuple{
        public:
                int node;
                int path;
                int cost;
        tuple(int node, int path, int cost){
            this->node=node;
            this->path=path;
            this->cost=cost;
        }
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<tuple> q;
        set<pair<int,int>> visited; // {node,path}
        int n=graph.size();
        int all=(1<<n)-1;
        for(int i=0;i<n;i++){
            int path= 1<<i;
            tuple node(i,path,1);
            q.push(node);
            visited.insert({i,path});
        }
        //BFS
        while(!q.empty()){
            tuple curr=q.front();
            q.pop();
            
            if(curr.path==all)
                return curr.cost-1;
            
            for(auto &adj:graph[curr.node]){
                int bothVisited = curr.path;
                bothVisited |= (1<<adj);
                
                if(visited.find({adj,bothVisited}) == visited.end()){
                    tuple newnode(adj,bothVisited,curr.cost+1);
                    q.push(newnode);
                    visited.insert({adj,bothVisited});
                    
                }
            }
        }
        
        return -1;
    }
};
