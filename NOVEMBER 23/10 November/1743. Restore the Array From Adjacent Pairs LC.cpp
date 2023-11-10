class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        map<int, vector<int>> adjacent;
        for(auto pair:pairs)
        {
            adjacent[pair[0]].push_back(pair[1]);
            adjacent[pair[1]].push_back(pair[0]);
        }
        vector<int> ans;
        for(auto p:adjacent)
        {
            if(p.second.size()==1)
            {
                ans.push_back(p.first);
                ans.push_back(p.second[0]);
                break;
            }
        }

        while(ans.size()<pairs.size() +1)
        {
            int tail = ans.back(), prev = ans[ans.size()-2];
            auto &next = adjacent[tail];
            if(next[0]!=prev)
                ans.push_back(next[0]);
            else
                ans.push_back(next[1]);
        }
        return ans;
    }
};
