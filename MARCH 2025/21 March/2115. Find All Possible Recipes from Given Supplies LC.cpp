class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int NoOfRecipes = recipes.size();
        unordered_set<string> setOfSupplies(supplies.begin(), supplies.end());
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        
        for(string recipe:recipes)
            indegree[recipe] = 0;

        for(int i=0; i<NoOfRecipes; i++)
        {
            for(int j=0; j<ingredients[i].size(); j++)
            {
                if(setOfSupplies.find(ingredients[i][j]) == setOfSupplies.end())
                {
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for(auto it:indegree)
        {
            if(it.second == 0)
                q.push(it.first);
        }

        vector<string> foundRecipes;
        while(!q.empty())
        {
            string recipe = q.front();
            q.pop();
            foundRecipes.push_back(recipe);
            for(auto next:graph[recipe])
            {
                indegree[next]--;
                if(indegree[next]==0)
                    q.push(next);
            }
        }
        return foundRecipes;
    }
};
