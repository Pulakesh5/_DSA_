class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupCount = m;
        for(auto &id:group)
        {
            if(id==-1)
                id = groupCount++;
        }

        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n,0);

        vector<vector<int>> groupGraph(groupCount);
        vector<int> groupIndegree(groupCount, 0);
        
        for(int i=0; i<n; i++)
        {
            for(auto item:beforeItems[i])
            {
                itemGraph[item].push_back(i);
                itemIndegree[i]++;
                if(group[item]!=group[i])
                {
                    groupGraph[group[item]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        vector<int> itemOrdering;
        if(topoSort(itemGraph, itemIndegree, itemOrdering) == false)
        {
            return {};
        }

        vector<int> groupOrdering;
        if(topoSort(groupGraph, groupIndegree, groupOrdering) == false)
        {
            return {};
        }
        vector<vector<int>> groupMap(groupCount);
        for(auto item:itemOrdering)
        {
            groupMap[group[item]].push_back(item);
        }

        vector<int> finalOrdering;
        for(auto group:groupOrdering)
        {
            finalOrdering.insert(finalOrdering.end(), groupMap[group].begin(), groupMap[group].end());
        }

        return finalOrdering;
    }
private:
    bool topoSort(vector<vector<int>> &graph, vector<int> &indegree, vector<int> &ordering)
    {
        queue<int> q;
        int graphSize = graph.size();
        for(int i=0; i<graphSize; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ordering.push_back(node);
            for(auto next:graph[node])
            {
                indegree[next]--;
                if(indegree[next]==0)
                    q.push(next);
            }
        }
        return ordering.size() == graphSize;
    }
};
