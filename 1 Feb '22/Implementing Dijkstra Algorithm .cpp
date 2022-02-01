// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V,INT_MAX);
        
        priority_queue<pair<int,int> > pq;
        
        distance[S]=0;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            int source=pq.top().second;
            //int dist=pq.top().first;
            pq.pop();
            for(auto &it: adj[source]){
                if( (distance[source] + it[1]) < distance[it[0]]){
                    distance[it[0]]=(distance[source] + it[1]);
                    pq.push({-1*distance[it[0]],it[0]}); // -1 for making it min priority queue
                }
            }
        }
        
        return distance;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
