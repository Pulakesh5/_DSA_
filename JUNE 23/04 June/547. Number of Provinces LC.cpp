class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> connected(n);
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(isConnected[i][j])
                {
                    connected[i].push_back(j);
                    connected[j].push_back(i);
                }
            }
            if(connected[i].size()==0) 
                connected[i].push_back(i);
        }

        int provinces = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                queue<int>  q;
                q.push(i);
                visited[i] = true;
                while(!q.empty())
                {
                    int city = q.front();
                    q.pop();
                    for(int j=0; j<connected[city].size(); j++)
                    {
                        if(!visited[connected[city][j]])
                        {
                            q.push(connected[city][j]);
                            visited[connected[city][j]] = true;
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};
