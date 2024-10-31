class Solution {
public:
    long long dp[101][101][101];
    const long long MAX = 1e9;
    long long fix(int i, int j, int k, vector<int> &robot, vector<vector<int>> &factory)
    {
        if(i==robot.size())
            return 0;
        if(j==factory.size())
            return MAX;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        long long choice1 = fix(i, j+1, 0, robot, factory);
        long long choice2 = (k<factory[j][1]) ? (abs(factory[j][0]-robot[i])+fix(i+1, j, k+1, robot, factory)) : MAX;
        
        return dp[i][j][k] = min(choice1, choice2);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        size_t robot_len = robot.size(), factory_len = factory.size();
        memset(dp, -1, sizeof(dp));
        return fix(0, 0, 0, robot, factory);
    }
};
