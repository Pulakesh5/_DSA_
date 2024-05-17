class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int len = quiet.size();
        vector<vector<int>> adj(len);
        vector<int> indegree(len);
        for(auto edge:richer) //edge[0]->edge[1]
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i=0; i<len; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        for(int i=0; i<len; i++)
        {
            cout<<i<<" : "<<indegree[i]<<endl;
        }
        vector<int> ordering;
        vector<int> answer(len);
        for(int i=0; i<len; i++)
            answer[i] = i;
        while(!q.empty())
        {
            int people = q.front();
            ordering.push_back(people);
            q.pop();
            for(auto next:adj[people])
            {
                if(quiet[answer[next]]>quiet[answer[people]])
                    answer[next] = answer[people];
                indegree[next]--;
                if(indegree[next]==0)
                    q.push(next);
            }
        }
        return answer;
    }
};
