class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // {time, person}
        pq.push({0,0});
        pq.push({0,firstPerson});
        
        vector<vector<vector<int>>> adj(n);

        for(vector<int> meeting:meetings) {
            adj[meeting[0]].push_back({meeting[2], meeting[1]});
            adj[meeting[1]].push_back({meeting[2], meeting[0]});
        }

        vector<bool> visited(n);
        while(!pq.empty()) {
            pair<int,int> pr = pq.top();
            pq.pop();

            if(visited[pr.second])
                continue;
            visited[pr.second] = true;
            for(vector<int>& next:adj[pr.second])
            {
                if(!visited[next[1]] && pr.first<=next[0])
                {
                    pq.push({next[0], next[1]});
                }
            }
        }

        vector<int> peopleWithSecret;
        for(int i=0; i<n; i++)
        {
            if(visited[i])
                peopleWithSecret.push_back(i);
        }
        return peopleWithSecret;
    }
};
