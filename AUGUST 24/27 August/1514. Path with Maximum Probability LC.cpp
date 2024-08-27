class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        int E = edges.size();
        
        for(int i=0; i<E; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> probability(n, INT_MIN);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        int node, nextNode;
        double prevProbability, nextProbability;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            prevProbability = it.first;
            node = it.second;
            for(auto next:adj[node])
            {
                nextProbability = next.second;
                nextNode = next.first;
                if(probability[nextNode]<prevProbability*nextProbability)
                {
                    probability[nextNode] = prevProbability*nextProbability;
                    pq.push({probability[nextNode], nextNode});
                }
            }
        }
        return (probability[end_node] == INT_MIN ? 0: probability[end_node]);
    }
};
