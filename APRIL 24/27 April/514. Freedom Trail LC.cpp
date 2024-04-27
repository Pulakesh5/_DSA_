class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int r = ring.size(), k = key.size();
        vector<int> pos[26];
        for(int i=0; i<r; i++)
            pos[ring[i]-'a'].push_back(i);
        vector<vector<int>> dp(r,vector<int>(key.size()));
        return countSteps(0, 0, ring, key, dp, pos);
    }
private:
    int countSteps(int p1, int p2, string &ring, string &key, vector<vector<int>> &dp, vector<int> pos[26])
    {
        if(p2 == key.size())
            return 0;
        if(dp[p1][p2])
            return dp[p1][p2];
        int r = ring.size(), minStep = INT_MAX, dist;
        for(int next:pos[key[p2]-'a'])
        {
            dist = abs(p1-next);
            minStep = min(minStep, min(dist, r-dist) + countSteps(next, p2+1, ring, key, dp, pos));
        }
        return dp[p1][p2] = (minStep+1);
    }
};
