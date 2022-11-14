class Solution {
public:
    
    int removeStones(vector<vector<int>>& stones) {
        map<int,vector<int>> rows,cols;
        int n=stones.size();

        for(int i=0;i<n;i++)
        {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }

        unordered_set<int> seen;

        function<int(int)> dfs;
        dfs = [&](int s) -> int
        {
            if (seen.count(s)) return 0;
            seen.insert(s);
            int r = stones[s][0], c = stones[s][1];
            for (auto it : rows[r]) dfs(it);
            for (auto it : cols[c]) dfs(it);
            return 1;
        };

        int not_removed=0;
        for(int i=0;i<n;i++)
        {
            not_removed+= dfs(i);
        }

        return n-not_removed;
    }
};


/*

* * -
* - *
- * *


* - *
- * -
* - *

*/
