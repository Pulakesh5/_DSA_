class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        vector<vector<vector<int>>> adj(n);
        for(auto flight:flights)
        {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        int cheapestFlight=INT_MAX, qs;
        vector<int> city;
        queue<vector<int>> q;
        q.push({src,0});
        distance[src] = 0;
        k+=2;

        while(!q.empty() && k--)
        {
            qs = q.size();
            while(qs--)
            {
                city = q.front();
                q.pop();

                if(city[0] == dst)
                {
                    cheapestFlight = min(cheapestFlight, city[1]);
                }
                for(auto adjCity:adj[city[0]])
                {
                    if(distance[adjCity[0]] > city[1]+adjCity[1])
                    {
                        distance[adjCity[0]] = city[1]+adjCity[1];
                        q.push({adjCity[0], city[1]+adjCity[1]});
                    }
                }   
            }
        }

        return cheapestFlight == INT_MAX ? -1 : cheapestFlight;
    }
};
