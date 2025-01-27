class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses);
        
        for(auto prereq:prerequisites)
        {
            adjList[prereq[0]].push_back(prereq[1]);
            indegree[prereq[1]]++;
        }

        vector<vector<int>> reachable(numCourses, vector<int>(numCourses,0));
        queue<int> q;
        
        for(int i=0; i<numCourses; i++)
        {
            // if(indegree[i]==0)
            {
                q.push(i);
                vector<int> vis(numCourses,0);
                vis[i] = 1;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(auto next:adjList[node])
                    {
                        reachable[i][next] = 1;
                        if(vis[next]==0)
                        {
                            vis[next] = 1;
                            q.push(next);
                        }
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto q:queries)
        {
            ans.push_back(reachable[q[0]][q[1]]);
        }
        return ans;
    }
};
