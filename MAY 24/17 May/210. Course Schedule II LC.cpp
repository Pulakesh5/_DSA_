class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependency(numCourses);
        vector<int> indegree(numCourses);
        for(auto &req:prerequisites)
        {
            dependency[req[1]].push_back(req[0]);
            indegree[req[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ordering;
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            ordering.push_back(course);
            for(auto next:dependency[course])
            {
                indegree[next]--;
                if(indegree[next]==0)
                    q.push(next);
            }
        }
        if(ordering.size()!=numCourses)
            return {};
        return ordering;
    }
};
