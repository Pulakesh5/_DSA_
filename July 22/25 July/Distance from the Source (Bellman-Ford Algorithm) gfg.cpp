class Solution{
	public:
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        int _INFINITY = 100000000;
        vector<int> Distance(V,_INFINITY);
        Distance[S] = 0;
        int E=adj.size();
        for(int i=0;i<(V-1);i++){
            for(int j=0;j<E;j++){
                if(Distance[adj[j][0]] != _INFINITY && Distance[adj[j][0]] + adj[j][2] < Distance[adj[j][1]])
                    Distance[adj[j][1]] = Distance[adj[j][0]] + adj[j][2];
            }
        }
        return Distance;
    }
};
