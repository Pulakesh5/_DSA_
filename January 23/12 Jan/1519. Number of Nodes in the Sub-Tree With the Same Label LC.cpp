class Solution {
public:
    vector<vector<int>> adjMatrix;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        adjMatrix.resize(n);
        vector<int> ans(n,0);
        
        for(auto edge:edges)
        {
            adjMatrix[edge[0]].push_back(edge[1]);
            adjMatrix[edge[1]].push_back(edge[0]);
        }
        int index=0;
        dfs(index, ans, labels);
        
        return ans;
    }

    vector<int> dfs(int index, vector<int> &ans, string &labels)
    {
        vector<int> count(26,0);
        count[labels[index]-'a']=1;
        ans[index]=1;
        
        for(int child:adjMatrix[index])
        {
            if(ans[child]==0)
            {
                vector<int> tmp = dfs(child,ans,labels);
                for(int i=0;i<26;i++)
                    count[i]+=tmp[i];
            }
        }
        
        ans[index]=count[labels[index]-'a'];
        
        return count;
    }
};
