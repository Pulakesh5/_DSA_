#define pid pair<int,double>
#define eps (double)(1e-5)
class Solution {
public:
    double dfs(vector<vector<pid>> &adjList, vector<double> &dp, vector<bool> &visited, int current, int end, double prevProbability)
    {
        if(current==end)
            return prevProbability;

        if(dp[current]!=-1.0)
            return dp[current];
        int next;
        double nextProbability, maxProbability = 0.0;
        for(int i=0; i<adjList[current].size(); i++)
        {
            next = adjList[current][i].first;
            nextProbability = adjList[current][i].second ;
            if(visited[next]==false && nextProbability>=eps)
            {
                visited[next] = true;
                maxProbability = max(maxProbability, dfs(adjList, dp, visited, next, end, nextProbability) * prevProbability);
                visited[next] = false;
            }
        }
        return dp[current] = max(dp[current], maxProbability);
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pid>> adjList(n);
        vector<bool> visited(n, false);
        vector<double> prob(n,INT_MIN);
        int NoOfEdges = edges.size();

        for(int i=0; i<NoOfEdges; i++)
        {
            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        } 
        visited[start] = true;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        prob[start] = 1;
        
        int node, next;
        double prevProb, nextProb;
        while(!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();

            prevProb = itr.first;
            node = itr.second;

            for(auto it:adjList[node])
            {
                next = it.first;
                nextProb = it.second;
                if(prob[next] < prevProb*nextProb)
                {
                    prob[next] = prevProb * nextProb;
                    pq.push({prob[next], next});
                }
            }
        }

        return prob[end] == INT_MIN ? 0.0 : prob[end];
       
    }
};
