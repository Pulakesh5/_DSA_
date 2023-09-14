  class Solution {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> result;
        void dfs(string vtex)
        {
            auto & edges = graph[vtex];
            while (!edges.empty())
            {
                string to_vtex = edges.top();
                edges.pop();
                dfs(to_vtex);
            }
            result.push_back(vtex);
        }
    public:
        vector<string> findItinerary(vector<vector<string>> tickets) {
            for (auto e : tickets)
                graph[e[0]].push(e[1]);
            dfs("JFK");
            reverse(result.begin(), result.end());
            return result;
        }
    };
