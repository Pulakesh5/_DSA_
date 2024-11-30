class Solution {
public: 
    map<int, bool> visited;
    void eulerPath(vector<vector<int>> &Path, int start, map<int,stack<int>> &adjList)
    {
        // if(outdegree[start]==0)
            // return;
        auto& stk = adjList[start];
        while(!stk.empty())
        {
            int next = stk.top();
            stk.pop();
            eulerPath(Path, next, adjList);
            Path.push_back({start, next});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        size_t N = pairs.size();
        map<int, int> indegree, outdegree;
        map<int, stack<int>> adjList;
        for(int i=0; i<N; i++)
        {
            indegree[pairs[i][1]]++;
            outdegree[pairs[i][0]]++;
            adjList[pairs[i][0]].push(pairs[i][1]);
        }
        
        // for(auto it:adjList)
        // {
        //     cout<<it.first<<" : ";
        //     for(int next:it.second)
        //         cout<<next<<" ";
        //     cout<<endl;
        // }

        int start = -1;
        for(auto it:adjList)
        {
            if(outdegree[it.first]-indegree[it.first] == 1)
            {
                start = it.first;
                break;
            }
        }
        if(start==-1)
            start = adjList.begin()->first;
        
        vector<vector<int>> Path;
        eulerPath(Path, start, adjList);

        // for(int node:path)
        //     cout<<node<<" -> ";
        // cout<<endl;
        reverse(Path.begin(), Path.end());
        
        return Path;
    }
};
