class Solution {
public: 
    int find_diameter(vector<vector<int>> &edges)
    {
        int N = edges.size()+1;
        vector<vector<int>> adjList(N);
        for(auto edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(N);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int start = -1;
        while(!q.empty())
        {
            int qs = q.size();
            start = q.front();
            for(int i=0; i<qs; i++)
            {
                int node = q.front();
                q.pop();
                for(int next:adjList[node])
                {
                    if(!visited[next])
                    {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }

        for(int i=0; i<N; i++)  visited[i] = false;
        // cout<<"start : "<<start<<endl;

        q.push(start);
        visited[start] = true;
        int diameter = -1;
        while(!q.empty())
        {
            int qs = q.size();
            for(int i=0; i<qs; i++)
            {
                
                int node = q.front();
                q.pop();
                // cout<<node<<" ";
                for(int next:adjList[node])
                {
                    if(!visited[next])
                    {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            // cout<<endl;
            diameter++;
        }
        
        // cout<<"diameter : "<<diameter<<endl;
        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int diameter1 = find_diameter(edges1);
        int diameter2 = find_diameter(edges2);
        
        return max({diameter1, diameter2, ((diameter1+1)/2 + (diameter2+1)/2 + 1)});
    }
};
