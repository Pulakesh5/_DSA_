class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> distance(n,INT_MAX);
        vector<vector<vector<int>>> adj(n);
        for(auto flight:flights)
        {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        int cheapestPrice=INT_MAX, qsize;
        vector<int> city;
        queue<vector<int>> q;
        q.push({src,0}); distance[src]=0;
        k+=2;
        
        while(!q.empty() && k--)
        {
            qsize=q.size();
            for(int qi=0;qi<qsize;qi++)
            {
                city = q.front();
                q.pop();

                if(city[0]==dst)
                {
                    cheapestPrice=min(cheapestPrice,city[1]);
                }
                for(auto adjCity:adj[city[0]])
                {
                    if(distance[adjCity[0]] > city[1] + adjCity[1])
                    {
                        distance[adjCity[0]] = city[1] + adjCity[1];
                        q.push({adjCity[0], city[1] + adjCity[1]});
                    }
                }
            }
        }

        return (cheapestPrice == INT_MAX ? -1 : cheapestPrice);

    }
};
