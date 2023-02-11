class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> visited(n,vector<int>(3,0));
        vector<int> distance(n,-1);

        for(auto edge:redEdges)
        {
            adj[edge[0]].push_back({edge[1],0});
        }
        for(auto edge:blueEdges)
        {
            adj[edge[0]].push_back({edge[1],1});
        }

        queue<pair<int,int>> qp;
        qp.push({0,2});
        visited[0][2]=1;
        distance[0]=0;

        int qs=0, path=0;
        // cout<<"testing...\n";
        // for(auto p:adj[0])
        // cout<<p.first<<" "<<p.second<<endl;

        while(!qp.empty())
        {
            qs = qp.size();
            for(int i=0;i<qs;i++)
            {
                pair<int,int> pr=qp.front();
                qp.pop();
                //cout<<"current {"<<pr.first<<", "<<pr.second<<"}\n\n";
                
                if(distance[pr.first]==-1)
                    distance[pr.first]=path;
                else
                    distance[pr.first]=min(path,distance[pr.first]);

                for(auto p:adj[pr.first])
                {
                    if(visited[p.first][p.second]==0 && pr.second!=p.second)
                    {
                        visited[p.first][p.second]=1;
                        qp.push(p);
                        //cout<<"pushing {"<<p.first<<", "<<p.second<<"}"<<endl;
                    }
                    // else
                    //     cout<<visited[p.first][pr.second]<<" : "<<p.first<<" "<<p.second<<endl;
                }
                //cout<<"----------------------------------"<<endl;
            }
            path++;
        }

        return distance;
    }
};
