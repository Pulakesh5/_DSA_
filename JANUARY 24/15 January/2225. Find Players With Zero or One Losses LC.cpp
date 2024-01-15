class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> lost(100001,-1);
        int maxp = 0;
        for (auto m : matches)
        {
            lost[m[0]] = max(0, lost[m[0]]);
            lost[m[1]] = max(0, lost[m[1]]) + 1;
            maxp = max(max(maxp, m[0]), m[1]);
        }
        
        vector<int> zero, ones;
        for (int i = 1; i <= maxp; ++i)
        {
            if (lost[i] == 0) zero.push_back(i);
            if (lost[i] == 1) ones.push_back(i);
        }
        
        return {zero,ones};
    }
};
