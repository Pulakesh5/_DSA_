class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> outdegree;
        for(vector<string> path:paths)
        {
            outdegree[path[0]]++;
            if(outdegree.find(path[1])==outdegree.end())
                outdegree[path[1]] = 0;
        }
        for(auto city:outdegree)
        {
            if(city.second==0)
                return city.first;
        }
        return "FU";
    }
};
