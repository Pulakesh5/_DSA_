class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        size_t q = queries.size();
        vector<int> shortestDistance(q);
        vector<vector<int>> adjList(n);
        for(int i=0; i<(n-1); i++)
            adjList[i].push_back(i+1);
        
        for(int j=0; j<q; j++)
        {
            adjList[queries[j][0]].push_back(queries[j][1]);
            queue<int> q;
            q.push(0);
            vector<bool> visited(n);
            visited[0] = true;
            int distance = 0;
            while(!q.empty())
            {
                size_t qsize = q.size();
                for(int i=0; i<qsize; i++)
                {
                    int node = q.front();
                    q.pop();
                    // cout<<node<<" "<<distance<<endl;
                    if(node == n-1)
                    {
                        // cout<<"shortest Distance to n-1 :"<<distance<<endl;
                        shortestDistance[j] = distance;
                        break;
                    }
                    for(int next:adjList[node])
                    {
                        if(!visited[next])
                        {
                            // cout<<"pushing "<<next<<endl;
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                }
                distance++;
            }
        }
        return shortestDistance;
    }
};
