class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int minutes=0;
        queue<vector<int>> qEmployee;
        vector<vector<int>> sub_ordinates(n+1);
        for(int i=0; i<n; i++)
        {
            if(manager[i]==-1) continue;
            sub_ordinates[manager[i]].push_back(i);
        }
        qEmployee.push({headID,0});
        while(!qEmployee.empty())
        {
            vector<int> employee = qEmployee.front();
            minutes = max(minutes, employee[1]);
            qEmployee.pop();

            for(int sub_ordinate:sub_ordinates[employee[0]])
            {
                qEmployee.push({sub_ordinate,informTime[employee[0]]+employee[1]});
            }
        }
        return minutes;
    }
};
