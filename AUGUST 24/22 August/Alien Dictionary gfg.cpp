class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<vector<int>> adj(k,vector<int>());
        vector<int> indegree(k,0);
        
        for(int i=0; i<(n-1); i++)
        {
            int idx1=i;
            int idx2=i+1;
            int minLen = min(dict[idx1].size(), dict[idx2].size());
            
            for(int j=0; j<minLen; j++)
            {
                if(dict[idx1][j]!=dict[idx2][j])
                {
                    adj[dict[idx1][j]-'a'].push_back(dict[idx2][j]-'a');
                    indegree[dict[idx2][j]-'a']++;
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i=0; i<k; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                // cout<<"pushing "<<i<<" "<<endl;
            }
        }
        string order = "";
        while(!q.empty())
        {
            int ch = q.front();
            order.push_back(ch+'a');
            q.pop();
            for(auto next:adj[ch])
            {
                indegree[next]--;
                if(indegree[next]==0)
                    q.push(next);
            }
        }
        // cout<<order<<" ";
        return order;
    }
};
