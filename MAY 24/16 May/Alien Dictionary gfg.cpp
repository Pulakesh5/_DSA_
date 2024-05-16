class Solution{
    private: 
    vector<int> topoSort(vector<vector<int>> &adj)
    {
        int K = adj.size();
        vector<int> indegree(K);
        for(int i=0; i<K; i++)
        {
            for(auto it:adj[i])
                indegree[it]++;
        }
        queue<int> q;
        for(int i=0; i<K; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topoOrder;
        while(!q.empty())
        {
            int node =q.front();
            q.pop();
            topoOrder.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return topoOrder;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> adj(K);
        string s1, s2;
        int minLen;
        for(int i=0; i<(N-1); i++)
        {
            s1 = dict[i];
            s2 = dict[i+1];
            minLen = min(s1.size(), s2.size());
            for(int j=0; j<minLen; j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> topoOrder = topoSort(adj);
        string order = "";
        for(auto it:topoOrder)
            order.push_back(it+'a');
        // cout<<order<<endl;
        return order;
    }
};
