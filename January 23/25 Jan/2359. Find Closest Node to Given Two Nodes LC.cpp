class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size(), k=0, qsize;
        vector<int> nodes={node1,node2};
        
        vector<vector<int>> distance(2,vector<int>(n,INT_MAX));

        for(int i=0;i<2;i++)
        {
            int node = nodes[i];
            queue<int> q;
            vector<bool> visited(n,false);
            q.push(node);
            k=0;
            
            while(!q.empty())
            {
                qsize = q.size();
                for(int j=0;j<qsize;j++)
                {
                    int next = q.front();
                    q.pop();
                    if(visited[next]==false)
                    {
                        if(edges[next]!=-1 )
                            q.push(edges[next]);
                        distance[i][next]=k;
                        visited[next]=true;
                        //cout<<edges[next]<<" "<<k<<endl;
                    }
                }
                k++;
            }

            cout<<endl;
        }
        
        int closest=-1;
        int minDistance=INT_MAX;

        for(int i=0;i<n;i++)
        {
            //cout<<i<<" : "<<distance[0][i]<<" , "<<distance[1][i]<<endl;
            if(minDistance > max(distance[0][i],distance[1][i]))
            {
                closest=i;
                minDistance = max(distance[0][i],distance[1][i]);
            }
        }

        return closest;
    }
};
