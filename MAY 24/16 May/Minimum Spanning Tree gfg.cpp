struct comp {
    bool operator()(const vector<int>& v1, const vector<int>& v2) const {
        return v1[0] > v2[0]; // Compare based on the first element
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<vector<int>,vector<vector<int>>, comp> pq;
        pq.push({0,0});
        int MST = 0, MSTSize=0;
        vector<int> visited(V,0);
        vector<int> edge;
        while(pq.size())
        {
            edge = pq.top();
            pq.pop();
            if(visited[edge[1]])
                continue;
            visited[edge[1]] = true;
            MSTSize++;
            MST+=edge[0];
            // cout<<MSTSize<<" : "<<MST<<" ["<<edge[1]<<"]\n";
            for(auto next:adj[edge[1]])
            {
                if(visited[next[0]])
                    continue;
                pq.push({next[1],next[0]});
                // cout<<next[0]<<", "<<next[1]<<endl;
            }
            if(MSTSize==V)
                return MST;
        }
        return -1;
    }
};
