class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto road:roads)
        {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }
        vector<long long> distance(n, LLONG_MAX), wayCount(n);

        distance[0] = 0;
        wayCount[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0,0);

        const long long MOD = 1e9+7;

        while(!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();

            if(dist > distance[node])
                continue;
            
            for(const auto& [next, time]:graph[node])
            {
                if(distance[node]+time < distance[next])
                {
                    distance[next] = distance[node] + time;
                    wayCount[next] = wayCount[node];
                    pq.emplace(distance[next], next);
                } else if(distance[node]+time == distance[next]) {
                    wayCount[next] = (wayCount[next] + wayCount[node])%MOD;
                }
            }
        }

        return wayCount[n-1];

    }
};
