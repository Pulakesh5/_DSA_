class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+5);
        vector<int> color(n+5,-1);
        for(vector<int> edge:dislikes)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                queue<int> q;
                q.push(i);
                color[i]=1;
                while(!q.empty())
                {
                    int person=q.front();
                    q.pop();
                    for(int dislike:adj[person])
                    {
                        if(color[dislike]==-1)
                        {
                            color[dislike]=1-color[person];
                            q.push(dislike);
                        }
                        else if(color[dislike]==color[person])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};
