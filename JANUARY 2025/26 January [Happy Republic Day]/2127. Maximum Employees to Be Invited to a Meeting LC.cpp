class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<int> indegree(n), chainLen(n);
        vector<bool> visited(n);

        for(int i=0; i<n; i++)
        {
            indegree[favorite[i]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            visited[node] = true;
            int fav = favorite[node];
            chainLen[fav] = chainLen[node] + 1;
            if(--indegree[fav] == 0)
                q.push(fav);
        }

        int maxCycle = 0, totalChains = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                int curr = i, cyclen=0;
                while(!visited[curr])
                {
                    visited[curr] = true;
                    curr = favorite[curr];
                    cyclen++;
                }

                if(cyclen==2)
                    totalChains += (2 + chainLen[i] + chainLen[favorite[i]]);
                else
                    maxCycle = max(cyclen, maxCycle);
            }
        }

        return max(maxCycle, totalChains);
    }
};
