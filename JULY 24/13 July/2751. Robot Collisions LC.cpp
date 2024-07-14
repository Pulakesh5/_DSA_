class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int len = positions.size();
        vector<vector<int>> robots(len);
        for(int i=0; i<len; i++)
        {
            robots[i] = {positions[i], healths[i], (directions[i]=='R'), i};
        }
        sort(robots.begin(), robots.end());
        stack<vector<int>> stk;
        for(int i=0; i<len; i++)
        {
            if(stk.empty())
            {
                stk.push(robots[i]);
                continue;
            }
            bool push = true;
            vector<int> topRobot;
            while(!stk.empty() && stk.top()[2]==1 && robots[i][2]==0)
            {
                topRobot = stk.top();
                stk.pop();
                if(topRobot[1]>=robots[i][1])
                {
                    push = false;
                    
                    if(topRobot[1]>0 && topRobot[1]>robots[i][1])
                    {
                        topRobot[1]--;
                        stk.push(topRobot);
                    }
                    break;
                }else
                    robots[i][1]--;
            }
            if(push)
                stk.push(robots[i]);
        }
        vector<vector<int>> survivedRobots;
        
        while(!stk.empty())
        {
            // vector<int> topRobot = stk.top();
            // cout<<topRobot[0]<<", "<<topRobot[1]<<", "<<topRobot[2]<<" "<<topRobot[3]<<endl;
            survivedRobots.push_back({stk.top()[3], stk.top()[1]});
            stk.pop();
        }
        sort(survivedRobots.begin(), survivedRobots.end());
        vector<int> remainingHealth;
        for(auto it:survivedRobots)
            remainingHealth.push_back(it[1]);
        return remainingHealth;
    }
};
