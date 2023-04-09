class Solution {
public:
    bool isCyclic=false;
    bool check(int node, string colors, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack, vector<vector<int>> &dp)
    {
        visited[node]=true;
        recStack[node]=true;
        
        for(int next:adj[node])
        {
            if(!visited[next])
            {
                if(check(next,colors,adj,visited,recStack,dp))
                    return true;
            }
            else if(recStack[next])
                return true;
            for(int i=0;i<26;i++)
            {
                dp[node][i]=max(dp[next][i],dp[node][i]);
            }
        }
        dp[node][colors[node]-'a']+=1;
        recStack[node]=false;
        return false;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        int visited=0;
        vector<vector<int>> adj(n);
        vector<vector<int>> dp(n,vector<int>(26,0));
        vector<int> indegree(n,0);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        unordered_set<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.insert(i);
            dp[i][colors[i]-'a']=1;
        }
        
        while(!q.empty())
        {
            int node = *q.begin();
            q.erase(node);
            visited++;
            for(int next:adj[node])
            {
                for(int i=0;i<26;i++)
                    dp[next][i]=max(dp[next][i],dp[node][i]+(colors[next]-'a'==i ? 1:0));
                //dp[next][colors[next]-'a']++;
                indegree[next]--;
                if(indegree[next]==0)
                    q.insert(next);
            }
        }
        int largestColorCount=1;
        for(int i=0;i<n;i++)
            largestColorCount=max(largestColorCount,*max_element(dp[i].begin(), dp[i].end()));
        if(visited==n)
            return largestColorCount;
        return -1;
    }
};
